// Auto-generated
let project = new Project('look_armory_1_0_0');

project.addSources('Sources');
project.addLibrary("C:/ArmorySDK/armory");
project.addLibrary("C:/ArmorySDK/iron");
project.addParameter('armory.trait.WalkNavigation');
project.addParameter("--macro keep('armory.trait.WalkNavigation')");
project.addShaders("build_look-armory/compiled/Shaders/*.glsl", { noembed: false});
project.addShaders("build_look-armory/compiled/Hlsl/*.glsl", { noprocessing: true, noembed: false });
project.addAssets("build_look-armory/compiled/Assets/**", { notinlist: true });
project.addAssets("build_look-armory/compiled/Shaders/*.arm", { notinlist: true });
project.addAssets("C:/ArmorySDK/armory/Assets/brdf.png", { notinlist: true });
project.addAssets("C:/ArmorySDK/armory/Assets/smaa_area.png", { notinlist: true });
project.addAssets("C:/ArmorySDK/armory/Assets/smaa_search.png", { notinlist: true });
project.addDefine('arm_deferred');
project.addDefine('arm_csm');
project.addDefine('rp_hdr');
project.addDefine('rp_renderer=Deferred');
project.addDefine('rp_shadowmap');
project.addDefine('rp_shadowmap_cascade=1024');
project.addDefine('rp_shadowmap_cube=512');
project.addDefine('rp_background=World');
project.addDefine('rp_render_to_texture');
project.addDefine('rp_compositornodes');
project.addDefine('rp_antialiasing=SMAA');
project.addDefine('rp_supersampling=1');
project.addDefine('rp_ssgi=SSAO');
project.addDefine('arm_noembed');
project.addDefine('arm_soundcompress');
project.addDefine('arm_audio');
project.addDefine('arm_skin');
project.addDefine('arm_particles');


resolve(project);
