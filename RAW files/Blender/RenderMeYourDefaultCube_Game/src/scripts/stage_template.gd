tool
extends Spatial


enum COLLIDER_TYPE {CONVEX, MESH, SMART}

const MODELS_PATH = "res://assets/models"
const SCENES_PATH = "res://src/scenes"
const STAGES_PATH = SCENES_PATH + "/stages"
const STAGE_TEMPLATE_PATH = STAGES_PATH + "/Stage_Template.tscn"

const PLAYER_SCENE_PATH = SCENES_PATH + "/Player_Template.tscn"
const PLAYER_BEHAVIOR_PATH = "res://src/scripts/player_template.gd"

const LIGHTS_SCENE_PATH = SCENES_PATH + "/Lights.tscn"

const COLLIDERS_JSON_PATH = "res://colliders_info/colliders.json"

const LIGHTS_JSON_PATH = "res://lights_info/lights_info.json"

const PLAYER_INFO_JSON_PATH = "res://player_info/player_info.json"

const COLLIDERS_MATRIX_PATH = "res://colliders_info/colliders_matrix.txt"

var camera_instance : Camera = null
var player_instance : KinematicBody = null
var lights_instance : Spatial = null

var player_height : float = 1.5
var player_radius : float = 0.2
var player_velocity : float = 1.0 # TODO: manage from blender

#var minimum_collider_size = 0.1
var initial_player_position : Vector3 = Vector3.ZERO
var initial_player_rotation : Vector3 = Vector3.ZERO
export var player_gravity_on : bool

var imported_scenes : Array
var scene_objects_list : Array
var scene_collider : StaticBody = null

var scene_colliding_matrix : Array
var matrix_dims : Vector3 = Vector3(50,50,50)
var matrix_offset : Vector3

func _ready():
	if Engine.editor_hint:
		print("Stage template present!")
		if get_child_count() == 0:
			self.mount_scene()
			#get_tree().quit()
		else:
			self.update_scene() # TODO
	else:
		self.play_game()


func add_collider(scene_object, collider_type, scene_to_save):
	"""
	if scene_collider == null:
		scene_collider = StaticBody.new()
		scene_collider.name = scene_to_save.name + "_Area"
		scene_to_save.add_child(scene_collider)
		scene_collider.set_owner(scene_to_save)
	var object_collider : CollisionShape = create_collision_shape(scene_object)
	object_collider.name = scene_object.name + "_collider"
	scene_collider.add_child(object_collider)
	object_collider.set_owner(scene_to_save)
	object_collider.transform.origin = scene_object.transform.origin
	"""
	match collider_type:
		COLLIDER_TYPE.CONVEX:
			print("Creating convex collider on: " + scene_object.name)
			self.create_convex_collision_shape(scene_object)
		COLLIDER_TYPE.MESH:
			print("Creating mesh collider on: " + scene_object.name)
			self.create_trimesh_collision_shape(scene_object)
		COLLIDER_TYPE.SMART:
			pass
			#self.create_collision_shape(scene_object, scene_to_save)


func add_light_point(scene_object, light_parameters):
	var new_omnilight : OmniLight
	new_omnilight = OmniLight.new()
	lights_instance.add_child(new_omnilight)
	new_omnilight.set_owner(lights_instance)
	new_omnilight.global_transform.origin = light_parameters["position"]
	# Lacks rotation
	new_omnilight.light_color = light_parameters["color"]
	new_omnilight.light_energy = light_parameters["energy"]/1000 # Aprox
	new_omnilight.shadow_enabled = true
	new_omnilight.omni_range = light_parameters["range"]


func add_player(position, rotation):
	player_instance = KinematicBody.new()
	var player_collision_shape : CollisionShape = CollisionShape.new()
	player_instance.add_child(player_collision_shape)
	player_collision_shape.set_owner(player_instance)
	var caps_shape : CapsuleShape = CapsuleShape.new()
	caps_shape.height = player_height
	caps_shape.radius = player_radius
	player_collision_shape.shape = caps_shape
	add_child(player_instance)
	player_collision_shape.global_rotate(Vector3.RIGHT, deg2rad(-90.0))
	player_instance.script = load(PLAYER_BEHAVIOR_PATH)
	self.initial_player_position = position
	player_instance.global_transform.origin = position
	player_instance.global_transform.basis = Basis(rotation)
	var camera_pos = position + Vector3(0, player_height/2,0)
	self.create_camera(camera_pos, rotation)
	
	var packed_scene = PackedScene.new()
	packed_scene.pack(player_instance)
	ResourceSaver.save(PLAYER_SCENE_PATH, packed_scene)
	player_instance.queue_free()


func add_scene(scene_file_path, with_name = "Scene"):
	print("Adding scene " + scene_file_path)
	var scene_instance = load(scene_file_path).instance()
	scene_instance.name = with_name
	add_child(scene_instance)
	scene_instance.set_owner(self)
	if scene_instance.name == "Player":
		print("Positioning player at:")
		print(self.initial_player_position)
		scene_instance.global_transform.origin = self.initial_player_position


func add_scenes(scene_filepaths):
	for scene_filepath in scene_filepaths:
		self.add_scene(scene_filepath)


func add_smart_collider(scene):
	print("Adding smart colliding...")
	
	# Create parent static body
	if scene_collider == null:
		scene_collider = StaticBody.new()
		scene_collider.name = scene.name + "_Area"
		scene.add_child(scene_collider)
		scene_collider.set_owner(scene)
		
	# Create boolean 3d matrix
	for x in range(matrix_dims.x):
		scene_colliding_matrix.append([])
		for y in range(matrix_dims.y):
			scene_colliding_matrix[x].append([])
			for z in range(matrix_dims.z):
				scene_colliding_matrix[x][y].append(false)
	#print(scene_colliding_matrix[34][24][9])
	
	# Get matrix bounds
	var min_x_object = null
	var min_y_object = null
	var min_z_object = null
	for ob in scene.get_children():
		if min_x_object == null:
			min_x_object = ob
		if min_y_object == null:
			min_y_object = ob
		if min_z_object == null:
			min_z_object = ob
		if ob is MeshInstance:
			# With AABB to start
			var ob_position : Vector3 = ob.transform.origin
			if ob_position.x < min_x_object.transform.origin.x:
				min_x_object = ob
			if ob_position.y < min_y_object.transform.origin.y:
				min_y_object = ob
			if ob_position.z < min_z_object.transform.origin.z:
				min_z_object = ob
	var corner_position : Vector3 = Vector3(min_x_object.transform.origin.x, min_y_object.transform.origin.y, min_z_object.transform.origin.z)
	print("Corner position: {" + str(corner_position.x) + "," + str(corner_position.y) + "," + str(corner_position.z) + "}")
	matrix_offset = corner_position
	
	# Fill matrix
	for ob in scene.get_children():
		if ob is MeshInstance:
			# With AABB to start
			var ob_aabb : AABB = ob.mesh.get_aabb()
			var position_with_offset : Vector3 = ob_aabb.position + ob.transform.origin - matrix_offset
			var rounded_position : Vector3 = position_with_offset.round()
			var aabb_size : Vector3 = ob_aabb.size.round()
			for x in range(aabb_size.x):
				for y in range(aabb_size.y):
					for z in range(aabb_size.z):
						scene_colliding_matrix[rounded_position.x + x][rounded_position.y + y][rounded_position.z + z] = true
	
	# Output matrix to text file
	output_matrix()
	
	# Recreate matrix
	for x in range(matrix_dims.x):
				for y in range(matrix_dims.y):
					for z in range(matrix_dims.z):
						pass
						# Try to group in rectangles before colliders creation
						"""
						if scene_colliding_matrix[x][y][z] == true:
							var new_collider_collision_shape : CollisionShape = CollisionShape.new()
							var box_shape : BoxShape = BoxShape.new()
							new_collider_collision_shape.shape = box_shape
							scene_collider.add_child(new_collider_collision_shape)
							new_collider_collision_shape.set_owner(scene)
							new_collider_collision_shape.transform.origin = Vector3(x,y,z)
						"""


func apply_import_changes(scene):
	print("Aplying changes to " + scene.name)
	var colliders_json = self.read_json_file(COLLIDERS_JSON_PATH)
	#print(colliders_json)
	var lights_json = self.read_json_file(LIGHTS_JSON_PATH)
	#self.get_all_scene_objects(scene.get_children())
	#for ob in scene_objects_list:
	for ob in scene.get_children():
		print("Changes to " + ob.name)
		if ob.name == "Camera": # CAMERA -> PLAYER
			if camera_instance == null: # Just the first camera found will be used
				var player_info_json = self.read_json_file(PLAYER_INFO_JSON_PATH)
				print(player_info_json)
				if player_info_json.has("GravityOn"):
					self.player_gravity_on = player_info_json["GravityOn"]
					print("Player gravity enabled:" + str(self.player_gravity_on))
				if player_info_json.has("InitialPositionX"):
					self.initial_player_position = Vector3(player_info_json["InitialPositionX"], player_info_json["InitialPositionZ"], -player_info_json["InitialPositionY"])
				if player_info_json.has("InitialRotationX"):
					self.initial_player_rotation = Vector3(0.0, player_info_json["InitialRotationZ"], player_info_json["InitialRotationY"])
				self.add_player(self.initial_player_position, self.initial_player_rotation)
		elif ob is MeshInstance: # MESHES
			if colliders_json.has(ob.name):
				if colliders_json[ob.name] == "none":
					print("...without collider!")
				elif colliders_json[ob.name] == "convex":
					print("...with convex collider!")
					self.add_collider(ob, COLLIDER_TYPE.CONVEX, scene)
				elif colliders_json[ob.name] == "mesh":
					print("...with mesh collider!")
					self.add_collider(ob, COLLIDER_TYPE.MESH, scene)
				elif colliders_json[ob.name] == "smart":
					print("...with smart collider!")
					self.add_collider(ob, COLLIDER_TYPE.SMART, scene)
		if lights_json.has(ob.name):
			if lights_instance == null:
				lights_instance = Spatial.new()
				lights_instance.name = "Lights"
				self.add_child(lights_instance)
				#lights_instance.set_owner(self)
			print("Adding light on :" + ob.name)
			var new_light_color : Color = Color(lights_json[ob.name + "ColorR"], lights_json[ob.name + "ColorG"], lights_json[ob.name + "ColorB"])
			var new_light_position : Vector3 = Vector3(lights_json[ob.name + "PositionX"], lights_json[ob.name + "PositionZ"], -lights_json[ob.name + "PositionY"])
			var new_light_rotation : Vector3 = Vector3.ZERO # TODO
			var new_light_energy : float = lights_json[ob.name + "Energy"]
			match lights_json[ob.name]:
				"POINT":
					var light_params_dict = {
						"color" : new_light_color,
						"energy" : new_light_energy,
						"range" : lights_json[ob.name + "Range"],
						"position" : new_light_position,
						"rotation" : new_light_rotation
					}
					self.add_light_point(ob, light_params_dict)
	#self.add_smart_collider(scene)
	return scene


func apply_import_changes_to_list(scenes_list, path):
	for scene in scenes_list:
		self.apply_import_changes(scene)


func clear_imported_scenes():
	pass


func create_camera(position, rotation):
	var rotation_helper : Spatial = Spatial.new()
	rotation_helper.name = "Rotation_Helper"
	player_instance.add_child(rotation_helper)
	rotation_helper.set_owner(player_instance)
	camera_instance = Camera.new()
	rotation_helper.add_child(camera_instance)
	camera_instance.set_owner(player_instance)
	camera_instance.make_current()
	rotation_helper.global_transform.origin = position
	#rotation_helper.rotate_x(deg2rad(-90.0))


#func create_collision_shape(scene_object, scene_to_save):
func create_collision_shape(scene_object):
	# TODO : SMART COLLIDER SET
	#scene_object.create_trimesh_collision()
	var new_collider_collision_shape : CollisionShape = CollisionShape.new()
	var sc_ob_mesh : Mesh = scene_object.get_mesh()
	new_collider_collision_shape.shape = sc_ob_mesh.create_convex_shape()
	return new_collider_collision_shape

func create_convex_collision_shape(scene_object):
	scene_object.create_convex_collision()


func create_trimesh_collision_shape(scene_object):
	scene_object.create_trimesh_collision()


func dir_contents(path, file_type = ".glb"):
	var files_to_import = []
	var dir = Directory.new()
	if dir.open(path) == OK:
		dir.list_dir_begin()
		var file_name = dir.get_next()
		while file_name != "":
			if dir.current_is_dir():
				pass
			else:
				print("Found file: " + file_name)
				if file_name.ends_with(file_type):
					files_to_import.append(file_name)
			file_name = dir.get_next()
	else:
		print("An error occurred when trying to access the path " + MODELS_PATH)
	return files_to_import


func get_all_scene_objects(scene_objects):
	for ob in scene_objects:
		scene_objects_list.append(ob)
		for ob2 in ob.get_children():
			scene_objects_list.append(ob2)
		"""
		if ob.get_child_count() > 0:
			scene_objects_list.append(ob)
			get_all_scene_objects(ob.get_children())
		else:
			scene_objects_list.append(ob)
		"""

func import_file(file_name):
	var filename_path = MODELS_PATH + "/" + file_name
	print("Importing " + file_name)
	var file_scene = load(filename_path).instance()
	var modified_scene = self.apply_import_changes(file_scene)
	var packed_scene = PackedScene.new()
	packed_scene.pack(modified_scene)
	var scene_file_path = SCENES_PATH + "/" + modified_scene.name + ".tscn"
	ResourceSaver.save(scene_file_path, packed_scene)
	file_scene.queue_free()
	#modified_scene.queue_free()
	imported_scenes.append(scene_file_path)


func import_files(files_to_import):
	if len(files_to_import) > 0:
		for f in files_to_import:
			self.import_file(f)
	else:
		print("No files to import.")


func mount_scene():
	print("Mounting scene...")
	var files_to_import = self.dir_contents(MODELS_PATH)
	import_files(files_to_import)
	#var all_scenes = self.dir_contents(SCENES_PATH, ".tscn")
	#print("Scenes:")
	#for sc in all_scenes:
		#print(sc)
	#self.apply_import_changes_to_list(imported_scenes, SCENES_PATH)
	self.add_scenes(imported_scenes)
	if lights_instance != null:
		repack_scene(lights_instance, LIGHTS_SCENE_PATH)
		lights_instance.queue_free()
	self.add_scene(PLAYER_SCENE_PATH, "Player")
	self.add_scene(LIGHTS_SCENE_PATH, "Lights")
	
	repack_scene(self, STAGE_TEMPLATE_PATH)
	#self.add_scene(COLLIDERS_PATH, "Colliders")


func output_matrix():
	var output_matrix_text = []
	var phrase : String
	for x in range(matrix_dims.x):
		for y in range(matrix_dims.y):
			for z in range(matrix_dims.z):
				phrase = "{" + str(x) + "," + str(y) + "," + str(z) + "} "  + str(scene_colliding_matrix[x][y][z]) + "\n"
				output_matrix_text.append(phrase)
	var file = File.new()
	file.open(COLLIDERS_MATRIX_PATH, File.WRITE)
	for ph in output_matrix_text:
		file.store_string(ph)
	file.close()


func play_game():
	print("Playing...")
	player_instance = find_node("Player")
	player_instance.gravity_enabled = self.player_gravity_on


func repack_scene(scene, filepath):
	var packed_scene = PackedScene.new()
	print("Repacking Scene: " + scene.name)
	packed_scene.pack(scene)
	ResourceSaver.save(filepath, packed_scene)


func read_json_file(filepath):
	var file = File.new()
	if not file.file_exists(COLLIDERS_JSON_PATH):
		print("Missing classes.json file.")
	else:
		file.open(filepath, file.READ)
		var json = file.get_as_text()
		var json_result = JSON.parse(json)
		file.close()
		return json_result.result


func smart_collider_update():
	print("Starting smart collider...")


func update_scene():
	print("Updating scene...")
	smart_collider_update()


# TEMP UNUSED CODE
"""
# Pack Colliders
var colliders_packed_scene = PackedScene.new()
print("Packing " + colliders_node.name)
colliders_packed_scene.pack(colliders_node)
ResourceSaver.save(COLLIDERS_PATH, colliders_packed_scene)
colliders_node.queue_free()
"""
"""
var colliders_node = Spatial.new()
colliders_node.name = "Colliders"
add_child(colliders_node)
#colliders_node.set_owner(self)

var box_shape : BoxShape = BoxShape.new()
var aabb : AABB = scene_object.get_aabb()
box_shape.set_extents((aabb.size/2) * scene_object.global_transform.basis.get_scale())
var v : Vector3 = Vector3(box_shape.extents.x, box_shape.extents.y, box_shape.extents.z)
if v.x < minimum_collider_size:
	v.x = minimum_collider_size
if v.y < minimum_collider_size:
	v.y = minimum_collider_size
if v.z < minimum_collider_size:
	v.z = minimum_collider_size
box_shape.set_extents(v)
return box_shape
"""
"""
print("Adding collider to " + scene_object.name)
var new_collider : StaticBody = StaticBody.new()
new_collider.name = scene_object.name + "_body"
var new_collider_collision_shape : CollisionShape = CollisionShape.new()

new_collider_collision_shape.shape = self.create_collision_shape(scene_object)
new_collider.global_transform.origin = get_calibrate_collider_center(scene_object)
colliders_node.add_child(new_collider)
new_collider.add_child(new_collider_collision_shape)
new_collider.set_owner(colliders_node)
new_collider_collision_shape.set_owner(colliders_node)
"""
"""
# Fix x rotation (blender to godot -90 degrees)
var new_rot : Vector3 = player_instance.get_rotation_degrees()
new_rot = new_rot + Vector3(-90.0, 0.0, 0.0)
camera_instance.set_rotation_degrees(new_rot)
"""
"""
func get_calibrate_collider_center(scene_object):
var new_origin_pos : Vector3 = Vector3.ZERO

return new_origin_pos

"""


#scene_object.create_trimesh_collision()
#scene_object.create_convex_collision()
"""
var new_collider : StaticBody = StaticBody.new()
new_collider.name = scene_object.name + "_body"
var new_collider_collision_shape : CollisionShape = CollisionShape.new()
var sc_ob_mesh : Mesh = scene_object.get_mesh()
new_collider_collision_shape.shape = sc_ob_mesh.create_convex_shape()
#new_collider.global_transform.origin = get_calibrate_collider_center(scene_object)
scene_object.add_child(new_collider)
new_collider.add_child(new_collider_collision_shape)
new_collider.set_owner(scene_to_save)
new_collider_collision_shape.set_owner(scene_to_save)
"""


