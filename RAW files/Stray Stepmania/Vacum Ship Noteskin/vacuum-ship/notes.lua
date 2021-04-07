--Well, Jousway, What have I done?... -JOELwindows7-
local skin_name= Var("skin_name")
return function(button_list, stepstype)
	local rots= {Left= 90, Down= 0, Up= 180, Right= 270, UpLeft= 90, UpRight= 180, DownLeft= 0, DownRight= 270, Center=0}
	local head_rots= {Left= 90, Down= 0, Up= 180, Right= 270, UpLeft= 0, UpRight= 0, DownLeft=0, DownRight=0, Center=0}
	local UpRight= {UpRight= 180}
	local hold_flips= {
		Left= "TexCoordFlipMode_None", Right= "TexCoordFlipMode_X",
		Down= "TexCoordFlipMode_None", Up= "TexCoordFlipMode_Y",
		UpLeft= "TexCoordFlipMode_None", UpRight= "TexCoordFlipMode_X",
	}
	local roll_flips= {
		Left= "TexCoordFlipMode_None", Right= "TexCoordFlipMode_X",
		Down= "TexCoordFlipMode_None", Up= "TexCoordFlipMode_Y",
		UpLeft= "TexCoordFlipMode_None", UpRight= "TexCoordFlipMode_X"
	}
	local rev_hold_flips= {
		Left= "TexCoordFlipMode_None", Right= "TexCoordFlipMode_X",
		Down= "TexCoordFlipMode_Y", Up= "TexCoordFlipMode_None",
		UpLeft= "TexCoordFlipMode_None", UpRight= "TexCoordFlipMode_X"
	}
	local rev_roll_flips= {
		Left= "TexCoordFlipMode_None", Right= "TexCoordFlipMode_X",
		Down= "TexCoordFlipMode_Y", Up= "TexCoordFlipMode_None",
		UpLeft= "TexCoordFlipMode_None", UpRight= "TexCoordFlipMode_X"
	}
	local tap_buttons= {
		Left= "Down", Right= "Down", Down= "Down", Up= "Down", 
		UpLeft= "DownLeft", UpRight= "DownLeft", -- shared for dance and pump
		DownLeft= "DownLeft", DownRight= "DownLeft", Center= "Center",
		
		ParaUp= "ParaUp", ParaLeft= "ParaUp", ParaRight= "ParaUp", ParaUpLeft= "ParaUpLeft", ParaUpRight= "ParaUpLeft" --Para Para

		
	}
	local hold_buttons= {
		Left= "Left", Right= "Left", Down= "Down", Up= "Down",
 		UpLeft= "DownLeft", UpRight= "DownLeft", DownLeft= "DownLeft", DownRight= "DownLeft", Center="Center"
	}
	local roll_buttons= {
		Left= "Left", Right= "Left", Down= "Down", Up= "Down",
 		UpLeft= "DownLeft", UpRight= "DownLeft", DownLeft= "DownLeft", DownRight= "DownLeft", Center="Center"
	}
	local Hold_Head= {
		Left= "Left", Right= "Left", Down= "Down", Up= "Down",
 		UpLeft= "DownLeft", UpRight= "DownLeft", DownLeft= "DownLeft", DownRight= "DownLeft", Center="Center"
	}
	local hold_length= {
		start_note_offset= -.5,
		end_note_offset= .5,
		head_pixs= 64,
		body_pixs= 32,
		tail_pixs= 80,
	}
	
	local roll_length= {
		start_note_offset= -.5,
		end_note_offset= .5,
		head_pixs= 64,
		body_pixs= 32,
		tail_pixs= 80,
	}
	
	local parts_per_beat= 48
	local tap_state_map= {
		parts_per_beat= parts_per_beat, quanta= {
			{per_beat= 1, states= {1, 2, 3, 4}}, -- 4th
			{per_beat= 2, states= {9, 10, 11, 12}}, -- 8th
			{per_beat= 3, states= {17, 18, 19, 20}}, -- 12th
			{per_beat= 4, states= {25, 26, 27, 28}}, -- 16th
			{per_beat= 6, states= {33, 34, 35, 36}}, -- 24th
			{per_beat= 8, states= {41, 42, 43, 44}}, -- 32nd
			{per_beat= 12, states= {49, 50, 51, 52}}, -- 48th
			{per_beat= 16, states= {57, 58, 59, 60}}, -- 64th
		},
	}

	--local lift_state_map= DeepCopy(tap_state_map)
	--[[for i, quanta in ipairs(lift_state_map.quanta) do
		--quanta.states[1]= quanta.states[1] + 4
		for i, states in ipairs(lift_state_map.quanta.states) do
			states[e]= states[e] + 4
		end
	end]]-- help me, how to make the script for multiple frames! -JOELwindows7

	--[[local lift_quanta={}
	for i, quantum in ipairs(tap_state_map.quanta) do
		local statum= {}
		for s, state in ipairs(quantum.states) do
			statum[s]= statum + 2
		end
		lift_quanta[i]= {per_beat= quantum.per_beat, states= statum}
	end
	local lift_state_map= {parts_per_beat= parts_per_beat, quanta= lift_quanta}]]--

	local lift_state_map= {
		parts_per_beat= parts_per_beat, quanta= {
			{per_beat= 1, states= {5, 6, 7, 8}}, -- 4th
			{per_beat= 2, states= {13, 14, 15, 16}}, -- 8th
			{per_beat= 3, states= {21, 22, 23, 24}}, -- 12th
			{per_beat= 4, states= {29, 30, 31, 32}}, -- 16th
			{per_beat= 6, states= {37, 38, 39, 40}}, -- 24th
			{per_beat= 8, states= {45, 46, 47, 48}}, -- 32nd
			{per_beat= 12, states= {53, 54, 55, 56}}, -- 48th
			{per_beat= 16, states= {61, 62, 63, 64}}, -- 64th
		},
	}
	local ahead_state_map= {
		parts_per_beat= parts_per_beat, quanta= {
			{per_beat= 1, states= {1}}, -- 4th
			{per_beat= 2, states= {3}}, -- 8th
			{per_beat= 3, states= {5}}, -- 12th
			{per_beat= 4, states= {7}}, -- 16th
			{per_beat= 6, states= {9}}, -- 24th
			{per_beat= 8, states= {11}}, -- 32nd
			{per_beat= 12, states= {13}}, -- 48th
			{per_beat= 16, states= {15}}, -- 64th
		},
	}
	local ihead_state_map= {
		parts_per_beat= parts_per_beat, quanta= {
			{per_beat= 1, states= {2}}, -- 4th
			{per_beat= 2, states= {4}}, -- 8th
			{per_beat= 3, states= {6}}, -- 12th
			{per_beat= 4, states= {8}}, -- 16th
			{per_beat= 6, states= {10}}, -- 24th
			{per_beat= 8, states= {12}}, -- 32nd
			{per_beat= 12, states= {14}}, -- 48th
			{per_beat= 16, states= {16}}, -- 64th
		},
	}
	local mine_state_map= NewSkin.generic_state_map(8, {1})
	local active_state_map= {
		parts_per_beat= parts_per_beat, quanta= {
			{per_beat= 1, states= {1, 2}}, -- 4th
			{per_beat= 2, states= {5, 6}}, -- 8th
			{per_beat= 3, states= {9, 10}}, -- 12th
			{per_beat= 4, states= {13, 14}}, -- 16th
			{per_beat= 6, states= {17, 18}}, -- 24th
			{per_beat= 8, states= {21, 22}}, -- 32nd
			{per_beat= 12, states= {25, 26}}, -- 48th
			{per_beat= 16, states= {29, 30}}, -- 64th
		},
	}
	local inactive_quanta= {}
	for i, quantum in ipairs(active_state_map.quanta) do
		local states= {}
		for s, state in ipairs(quantum.states) do
			states[s]= state + 2
		end
		inactive_quanta[i]= {per_beat= quantum.per_beat, states= states}
	end
	local inactive_state_map= {parts_per_beat= parts_per_beat, quanta= inactive_quanta}


	local columns= {}
	for i, button in ipairs(button_list) do
		local hold_tex= hold_buttons[button] .. " Hold 8x4.png"
		local roll_tex= roll_buttons[button] .. " Roll 8x4.png"
		columns[i]= {
			width= 64,
			anim_time= 1,
			anim_uses_beats= true,
			hold_gray_percent= .25,
			use_hold_heads_for_taps_on_row= false,
			padding= 0,
			quantum_time= 1,
			taps= {
				NewSkinTapPart_Tap= {
					state_map= tap_state_map,
					actor= Def.Sprite{Texture= tap_buttons[button] .. " Tap Note 8x16.png",
						InitCommand= function(self) self:rotationz(rots[button]) end}},
				NewSkinTapPart_Mine= {
					state_map= mine_state_map,
					actor= Def.Sprite{Texture= NEWSKIN:get_path(skin_name, "Mine 8x1.png")}},
				NewSkinTapPart_Lift= { -- don't fuck lifts!
					state_map= lift_state_map,
					--actor= Def.Sprite{Texture= NEWSKIN:get_path(skin_name, "Mine 8x1.png"),
					--actor= Def.Sprite{Texture= NEWSKIN:get_path(skin_name, "Lift 8x1.png"),
					actor= Def.Sprite{Texture= NEWSKIN:get_path(skin_name, tap_buttons[button] .. " Tap Note 8x16.png"),
						InitCommand= function(self) self:rotationz(rots[button]) end}},
						
			},
			--[[
			optional_taps= {
				NewSkinTapOptionalPart_HoldHead= {
					state_map= ahead_state_map,
					inactive_state_map= ihead_state_map,
					actor= Def.Sprite{Texture= Hold_Head[button].." Hold Head 2x8.png",
					InitCommand= function(self) self:rotationz(head_rots[button]):rotationy(UpRight[button] or 0) end}},
				NewSkinTapOptionalPart_RollHead= {
					state_map= ahead_state_map,
					inactive_state_map= ihead_state_map,
					actor= Def.Sprite{Texture= Hold_Head[button].." Hold Head 2x8.png",
					InitCommand= function(self) self:rotationz(head_rots[button]):rotationy(UpRight[button] or 0) end}},
			},
			]]--
			holds= {
				TapNoteSubType_Hold= {
					{
						state_map= inactive_state_map,
						textures= {hold_tex},
						flip= hold_flips[button],
						length_data= hold_length,
					},
					{
						state_map= active_state_map,
						textures= {hold_tex},
						flip= hold_flips[button],
						length_data= hold_length,
					},
				},
				TapNoteSubType_Roll= {
					{
						state_map= inactive_state_map,
						textures= {roll_tex},
						flip= roll_flips[button],
						length_data= roll_length,
					},
					{
						state_map= active_state_map,
						textures= {roll_tex},
						flip= roll_flips[button],
						length_data= roll_length,
					},
				},
			},
			reverse_holds= {
				TapNoteSubType_Hold= {
					{
						state_map= inactive_state_map,
						textures= {hold_tex},
						flip= rev_hold_flips[button],
						length_data= hold_length,
					},
					{
						state_map= active_state_map,
						textures= {hold_tex},
						flip= rev_hold_flips[button],
						length_data= hold_length,
					},
				},
				TapNoteSubType_Roll= {
					{
						state_map= inactive_state_map,
						textures= {roll_tex},
						flip= rev_roll_flips[button],
						length_data= roll_length,
					},
					{
						state_map= active_state_map,
						textures= {roll_tex},
						flip= rev_roll_flips[button],
						length_data= roll_length,
					},
				},
			},
		}
	end
	return {
		columns= columns,
		vivid_operation= true, -- output 200%
	}
end
