signal iAmReady

#https://docs.godotengine.org/en/3.1/tutorials/io/background_loading.html
var thread
var mutex
var sem

var time_max = 100 # msec

var queue = []
var pending = {}

func _lock(caller):
	mutex.lock()

func _unlock(caller):
	mutex.unlock()

func _post(caller):
	sem.post()

func _wait(caller):
	sem.wait()


func queue_resource(path, p_in_front = false):
	_lock("queue_resource")
	if path in pending:
		_unlock("queue_resource")
		return

	#elif ResourceLoader.has(path):
	elif ResourceLoader.has_cached(path): # https://docs.godotengine.org/en/3.1/classes/class_resourceloader.html
		var res = ResourceLoader.load(path)
		pending[path] = res
		_unlock("queue_resource")
		return
	else:
		var res = ResourceLoader.load_threaded_request(path)
		res.set_meta("path", path)
		if p_in_front:
			queue.insert(0, res)
		else:
			queue.push_back(res)
		pending[path] = res
		_post("queue_resource")
		_unlock("queue_resource")
		return

func cancel_resource(path):
	_lock("cancel_resource")
	if path in pending:
		if pending[path] is ResourceLoader:
			queue.erase(pending[path])
		pending.erase(path)
	_unlock("cancel_resource")

func get_progress(path):
	_lock("get_progress")
	var ret = -1
	if path in pending:
		if pending[path] is ResourceLoader:
			ret = float(pending[path].get_stage()) / float(pending[path].get_stage_count())
		else:
			ret = 1.0
	_unlock("get_progress")

	return ret

func is_ready(path):
	var ret
	_lock("is_ready")
	if path in pending:
		ret = !(pending[path] is ResourceLoader)
	else:
		ret = false

	_unlock("is_ready")
	emit_signal("iAmReady")
	return ret

func _wait_for_resource(res, path):
	_unlock("wait_for_resource")
	while true:
		RenderingServer.sync()
		OS.delay_usec(16000) # wait 1 frame
		_lock("wait_for_resource")
		if queue.size() == 0 || queue[0] != res:
			return pending[path]
		_unlock("wait_for_resource")


func get_resource(path):
	_lock("get_resource")
	if path in pending:
		if pending[path] is ResourceLoader:
			var res = pending[path]
			if res != queue[0]:
				var pos = queue.find(res)
				queue.remove(pos)
				queue.insert(0, res)

			res = _wait_for_resource(res, path)

			pending.erase(path)
			_unlock("return")
			return res

		else:
			var res = pending[path]
			pending.erase(path)
			_unlock("return")
			return res
	else:
		_unlock("return")
		return ResourceLoader.load(path)

func thread_process():
	_wait("thread_process")

	_lock("process")

	while queue.size() > 0:

		var res = queue[0]

		_unlock("process_poll")
		var ret = res.poll()
		_lock("process_check_queue")

		if ret == ERR_FILE_EOF || ret != OK:
			var path = res.get_meta("path")
			if path in pending: # else it was already retrieved
				pending[res.get_meta("path")] = res.get_resource()

			queue.erase(res) # something might have been put at the front of the queue while we polled, so use erase instead of remove

	_unlock("process")


func thread_func(u):
	while true:
		thread_process()

func start():
	mutex = Mutex.new()
	sem = Semaphore.new()
	thread = Thread.new()
	thread.start(Callable(self, "thread_func").bind(0))


