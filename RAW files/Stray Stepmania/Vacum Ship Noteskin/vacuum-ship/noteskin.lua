--I am the bone of my noteskin
--Arrows are my body, and explosions are my blood
--I have created over a thousand noteskins
--Unknown to death
--Nor known to life
--Have withstood pain to create many noteskins
--Yet these hands will never hold anything
--So as I pray, Unlimited Stepman Works -Jousway-

return {
	notes= "notes.lua",
	layers= {"receptors.lua", "explosions.lua"},
	supports_all_buttons= false,
	buttons= {
		"Left", "Down", "Up", "Right",
		"UpLeft", "UpRight", "DownLeft", "DownRight", "Center",

		"FootUpLeft", "HandLrLeft", "HandUpLeft", "FootDown", "HandUpRight", "HandLrRight", "FootUpRight",
		"HandLeft", "FootDownLeft", "HandDown", "HandUp", "FootDownRight", "HandRight",

		"ParaLeft", "ParaUpLeft", "ParaUp", "ParaUpRight", "ParaRight",

		"Scratch", "Scratch up", "Scratch down", "Key1", "Key2", "Key3", "Key4", "Key5", "Key6", "Key7",
		"Left White", "Left Yellow", "Left Green", "Left Blue", "Red", "Right Blue", "Right Green", "Right Yellow", "Right White",

		"DownLeftFoot", "LeftFoot", "UpLeftFoot", "UpLeftFist", "LeftFist", "DownLeftFist", "DownRightFist", "RightFist", "UpRightFist", "UpRightFoot", "RightFoot", "DownRightFoot",
	},
	fallback= "",
	
	skin_parameters= {
		explosions= {
			particles= true,
			particle_dist= 128,
			particle_life= 1,
			particle_size= 32,
			num_particles= 16,
			particle_blend= "BlendMode_WeightedMultiply",
		},
		receptors= {
			warning_time= 1,
		},
	},
	skin_parameter_info= { -- I got these from Kyzentun + Jousway's default!
		explosions= {
			translation= {
				en= {title= "Explosions", explanation= "Options for the explosion effects."},
			},
			particles= {
				translation= {
					en= {title= "Particles", explanation= "When set to true, particles will fly out when a note is hit."},
			}},
			particle_dist= {
				type= "int",
				min= 0, max= 2000, translation= {
					en= {title= "Particle Distance", explanation= "A higher number makes the particles fly further."},
				},
			},
			particle_life= {
				type= "float", min= .1, max= 10, translation= {
					en= {title= "Particle Life", explanation= "Number of seconds particles live for."},
				},
			},
			particle_size= {
				type= "int", min= 0, max= 2000, translation= {
					en= {title= "Particle Size", explanation= "A higher number makes the particles larger."},
				},
			},
			num_particles= {
				type= "int", min= 0, max= 64, translation= {
					en= {title= "Particle Count", explanation= "A higher number makes the particles lag gameplay more."},
				},
			},
			particle_blend= {
				choices= {
					"BlendMode_Normal", "BlendMode_Add", "BlendMode_Subtract",
					"BlendMode_Modulate", "BlendMode_CopySrc", "BlendMode_AlphaMask",
					"BlendMode_AlphaKnockOut", "BlendMode_AlphaMultiply",
					"BlendMode_WeightedMultiply", "BlendMode_InvertDest",
					"BlendMode_NoEffect"},
				translation= {
					en= {
						title= "Particle Blend Mode", explanation= "Changes how the particles are blended.",
						choices= {
							"Normal", "Add", "Subtract",
							"Modulate", "Copy Source", "Alpha Mask",
							"Alpha Knock Out", "Alpha Multiply",
							"Weighted Multiply", "Invert Dest",
							"No Effect"},
					},
				},
			},
		},
		receptors= {
			translation= {
				en= {title= "Receptors", explanation= "Options for receptor effects."},
			},
			warning_time= {
				type= "float", min= 0, max= 10, translation= {
					en= {title= "Warning Time", explanation= "Turns the receptor red seconds before an arrow arrives."},
				},
			},
		},
	},
}
