pastebinID = "Xe9gGj35"
fileName = "MAC1_NyanCat.lua"
monitorNambers = {}

Alat = peripheral.getNames()
for i=1,#Alat do
    if string.match(Alat[i],"monitor") then
        monitorNambers[#monitorNambers+1] = Alat[i]
    end
end

print("MAC1 Nyan Cat run all, JOELwindows7 initiative\n")
print("Connects through modem! Not sides")
print("youtu.be/QdgZZwM0Beg\n")
print("pastebin.com/"..pastebinID.."\n")
print("Downloading Nyan Cat...")
shell.run("pastebin","get "..pastebinID.." "..fileName)
for i=1,#monitorNambers do
    --shell.openTab("monitor", monitorNambers[i].." pastebin run "..pastebinID.."")
	shell.openTab("monitor", monitorNambers[i].." "..fileName)
end

--youtu.be/QdgZZwM0Beg
--pastebin.com/Xe9gGj35