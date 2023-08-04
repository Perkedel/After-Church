print("Welcome to chat Server!")
ServerName = "Perkedel"
MonitorJoinName = "MonitorSayaSendiri"
SelfJoinName = "DiriSayaSendiri"
MonitorName = "right"
MonitorHost = "left"

print("Initiating Repeater...")
shell.openTab("repeat")

print("Hostname = "..ServerName.." at monitor "..MonitorHost.."\n")
shell.openTab("monitor", MonitorHost.." chat host "..ServerName)

print("\nNow also joining myself as = "..MonitorJoinName.." at monitor "..MonitorName.."\n")
sleep(5)
shell.openTab("monitor", MonitorName.." chat join "..ServerName.." "..MonitorJoinName)

print("\nAdditionally, joinning chat internally as "..SelfJoinName.."\n")
shell.openTab("chat","join "..ServerName.." "..SelfJoinName)

print("\nEnjoy your chat day, on the these monitors and next tab. thancc\n")
print("\nBy JOELwindows7\nPerkedel Technologies\nGNU GPL v3")
-- Yeah.