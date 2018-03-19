//CID SPOOFER
//
//SILICAANDPINA!


#include <stdio.h>
#include <stdarg.h>
#include <vitasdkkern.h>
#include <taihen.h>
#include <string.h>

static int hook = -1;
static tai_hook_ref_t ref_hook;
int ret;
SceUID fd;

int getFileSize(const char *file) {
	SceUID fd3 = ksceIoOpen(file, SCE_O_RDONLY, 0);
	if (fd3 < 0)
		return fd3;
	int fileSize = ksceIoLseek(fd3, 0, SCE_SEEK_END);
	ksceIoClose(fd3);
	return fileSize;
}

int WriteFile(char *file, void *buf, int size) {
	SceUID fd = ksceIoOpen(file, SCE_O_WRONLY | SCE_O_CREAT | SCE_O_TRUNC, 0777);
	if (fd < 0)
		return fd;

	int written = ksceIoWrite(fd, buf, size);

	ksceIoClose(fd);
	return written;
}


static int ksceSblAimgrGetConsoleId_patched(char CID[16]) {
	ret = TAI_CONTINUE(int,ref_hook,CID);
        
        if(getFileSize("ux0:CID.bin") < 0)
        {
            WriteFile("ux0:CID.bin", CID, 16);
        }
        
        SceUID fd = ksceIoOpen("ux0:CID.bin", SCE_O_RDWR, 0);
        ksceIoRead(fd, CID, 16);
        ksceIoClose(fd);
        //ConsoleID = CID;
	return ret;
}	


void _start() __attribute__ ((weak, alias ("module_start")));
int module_start(SceSize argc, const void *args)
{
	hook = taiHookFunctionExportForKernel(KERNEL_PID,
		&ref_hook, 
		"SceSblSsMgr",
		TAI_ANY_LIBRARY,
		0xFC6CDD68, //ksceSblAimgrGetConsoleId
		ksceSblAimgrGetConsoleId_patched);
	return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args)
{
	if (hook >= 0) taiHookReleaseForKernel(hook, ref_hook);   
	return SCE_KERNEL_STOP_SUCCESS;
}
