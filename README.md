# cidSpoofer
Spoof CID (ConsoleID) on PSVITA

Could possibly be used to unban your console from PSN            


add to your \*KERNEL line in config.txt.                  

Simply edit ux0:CID.BIN this file is your CID as raw binary data               
NP Modules store your CID in memory at bootup, so you will have to reboot if you want it to effect those.      

Ever wondered what a console ban looks like?               
set your cid to 00000001010400100C0AA7E2B9F68F7D (Contributed by u/Pahan55)           
to find out              

What if you dont want a console ban?        
well you could try spoofing to 00000001010500100C04BDEF4B8F0A87,                        
Before anyone freaks out about me sharing someones CID. this was allready public            
i extracted it from MLTActivator, at this current time of writing this it isnt banned!          


If you dont see a CID.BIN after installing, try connecting to PSN or open VitaIDENT,
the CID.BIN is only written after ksceSblAimgrGetConsoleId is called.

!!Works on 3.65!!

Download: https://bitbucket.org/SilicaAndPina/cidspoofer/downloads/cidSpoof.skprx   