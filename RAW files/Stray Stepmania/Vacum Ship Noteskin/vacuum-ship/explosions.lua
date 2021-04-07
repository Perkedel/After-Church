--Wow dude, they're all here! -JOElwindows7-

--These are from Kyzentun + Jousway default
local hold_colors= {
	TapNoteSubType_Hold= {1, 1, 0, 1},
	TapNoteSubType_Roll= {1, 0, 1, 1},
	TapNoteSubType_Checkpoint= {0, 1, 1, 1},
}
local white= {1, 1, 1, 1}
--------------------------------------------




return function(button_list, stepstype, skin_params)
	--This too!
	local particle_directions= {}
	local explosion_params= skin_params.explosions
	local num_particles= explosion_params.num_particles
	local start_angle= 0
	local end_angle= 180
	local parsize= explosion_params.particle_size
	local pardist= explosion_params.particle_dist
	local particle_life= explosion_params.particle_life
	local have_particles= explosion_params.particles
	if have_particles then
		local angle_per_particle= (end_angle - start_angle) / (num_particles - 1)
		for i= 0, num_particles-1 do
			local angle= start_angle + (i * angle_per_particle)
			local radan= angle / 180 * math.pi
			particle_directions[i+1]= {
				angle= angle, x= math.cos(radan)*pardist, y= math.sin(radan)*pardist}
		end
	end
	------------------------ and stuffs

	local ret= {}
	local rots= {
		Left= 90, Down= 0, Up= 180, Right= 270,
		UpLeft= 90, UpRight= 180, 
		DownLeft= 0, DownRight= 270,  Center= 0
	}
	local tap_redir= {
		Left= "Down", Right= "Down", Down= "Down", Up= "Down", 
		UpLeft= "DownLeft", UpRight= "DownLeft", -- shared for dance and pump
		DownLeft= "DownLeft", DownRight= "DownLeft", Center= "Center"
	}
	for i, button in ipairs(button_list) do
		local particles= {}
		local particle_frames= {}
		if have_particles then
			local curr_particle= 1
			particle_frames.ReverseChangedCommand= function(self, param)
				self:zoomy(param.sign)
			end
			particle_frames.ColumnJudgmentCommand= function(self, param)
				local diffuse= {
					TapNoteScore_W1= {1, 1, 1, 1},
					TapNoteScore_W2= {1, 1, .3, 1},
					TapNoteScore_W3= {0, 1, .4, 1},
					TapNoteScore_W4= {.3, .8, 1, 1},
					TapNoteScore_W5= {.8, 0, .6, 1},
					TapNoteScore_Miss= {.8, 0, 0, 1},
					HoldNoteScore_Held= {1, 1, 1, 1},
				}
				local exp_color= diffuse[param.tap_note_score or param.hold_note_score]
				if exp_color then
					particles[curr_particle]:playcommand("explode", {color= exp_color})
					curr_particle= curr_particle + 1
					if not particles[curr_particle] then curr_particle= 1 end
				end
			end
			for part_id= 1, 10 do
				local parts= {
					InitCommand= function(self)
						if rots[button] then
							self:rotationz(-rots[button])
						end
						particles[part_id]= self:playcommand("hide")
					end,
					explodeCommand= function(self)
						self:hibernate(0):finishtweening():sleep(1):queuecommand("hide")
					end,
					hideCommand= function(self)
						self:hibernate(math.huge)
					end
				}
				for p= 1, num_particles do
					parts[p]= Def.Quad{
						InitCommand= function(self)
							local direction= particle_directions[p]
							self:setsize(parsize, parsize):diffuseupperleft{1, 1, 1, 0}
								:diffuselowerright{1, 1, 1, 0}
								:blend(explosion_params.particle_blend)
								:rotationz(direction.angle+45)
						end,
						explodeCommand= function(self, param)
							local direction= particle_directions[p]
							self:finishtweening()
								:diffuseupperright(param.color):diffuselowerleft(param.color)
								:zoom(1):xy(0, 0)
								:decelerate(particle_life)
								:zoom(0):xy(direction.x, direction.y)
						end
					}
				end
				particle_frames[part_id]= Def.ActorFrame(parts)
			end
		end

		local column_frame= Def.ActorFrame{
			InitCommand= function(self)
				self:rotationz(rots[button] or 0)
					:draworder(newfield_draw_order.explosion)
			end,
			WidthSetCommand= function(self, param)
				param.column:set_layer_fade_type(self, "FieldLayerFadeType_Explosion")
			end,
			Def.Sprite{
				Texture= "Tap Explosion.png", InitCommand= function(self)
					self:visible(false):SetAllStateDelays(.05)
				end,
				ColumnJudgmentCommand= function(self, param)
					local diffuse= {
						TapNoteScore_W1= {1, 1, 1, 1},
						TapNoteScore_W2= {1, 1, .3, 1},
						TapNoteScore_W3= {0, 1, .4, 1},
						TapNoteScore_W4= {.3, .8, 1, 1},
						TapNoteScore_W5= {.8, 0, .6, 1},
						HoldNoteScore_Held= {1, 1, 1, 1},
					}
					local exp_color= diffuse[param.tap_note_score or param.hold_note_score]
					if exp_color then
						self:stoptweening()
							:diffuse(exp_color):zoom(1):diffusealpha(0.9):visible(true)
							:linear(0.1):zoom(2):diffusealpha(.3)
							:linear(0.06):diffusealpha(0)
							:sleep(0):queuecommand("hide")
					end
				end,
				hideCommand= function(self)
					self:visible(false)
				end,
			},
			Def.Sprite{
				Texture= "Hold Explosion.png", InitCommand= function(self)
					self:visible(false):SetAllStateDelays(.05)
				end,
				HoldCommand= function(self, param)
					if param.start then
						self:finishtweening()
							:diffuse(white):zoom(1):diffusealpha(1):visible(true)
							:diffuseblink():effectcolor1(hold_colors[param.type])
							:effectcolor2(white):effectperiod(.1)
					elseif param.finished then
						self:stopeffect():linear(0.06):diffusealpha(0)
							:sleep(0):queuecommand("hide")
					else
						--self:zoom(1)
						self:zoom(param.life * 1.25)
					end
				end,
				hideCommand= function(self)
					self:visible(false)
				end,
			},
		}
		if have_particles then
			column_frame[#column_frame+1]= Def.ActorFrame(particle_frames)
		end
		ret[i]= column_frame
	end
	return ret
end
