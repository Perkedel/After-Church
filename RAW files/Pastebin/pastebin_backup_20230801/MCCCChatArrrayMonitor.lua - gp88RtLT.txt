ServerName = "Perkedel"
JoinName = "MonitorMe"
--monitorName = "monitor_0"

print("This is Chat MultiMonitor Manager")

Alat = peripheral.getNames()
Monitors = {}
for i=1,#Alat do
    if string.match(Alat[i],"monitor") then
        Monitors[#Monitors+1] = Alat[i]
    end
end

print("Joinning "..ServerName.." as "..JoinName.." at many monitors")
sleep(5)
for i=1,#Monitors do
    shell.openTab("monitor", Monitors[i].." chat join "..ServerName.." "..JoinName)
end
print("Enjoy Chat Broadcast! thancc. cool and good")

print("\nBy JOELwindows7\nPerkedel Technologies\nGNU GPL v3")