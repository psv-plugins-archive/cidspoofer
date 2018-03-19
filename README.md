# cidSpoofer
Spoof CID (ConsoleID) on PSVITA

Could possibly be used to unban your console from PSN            


add to your \*KERNEL line in config.txt.                  

Simply edit ux0:CID.BIN this file is your CID as raw binary data               
NP Modules store your CID in memory at bootup, so you will have to reboot if you want it to effect those.      

Ever wondered what a console ban looks like?               
set your cid to 00000001010400100C0AA7E2B9F68F7D (Contributed by u/Pahan55)           
to find out              

Alternatively here is a valid, not-banned CID, this was extracted from MLTActivator.           
If you have a banned vita, change your CID to this and you can access PSN again.          
00000001010500100C04BDEF4B8F0A87     


If you dont see a CID.BIN after installing, try connecting to PSN or open VitaIDENT,
the CID.BIN is only written after ksceSblAimgrGetConsoleId is called.

!!Works on 3.65!!
