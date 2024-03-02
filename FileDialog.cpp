//
// Created by cryptic on 02/03/24.
//

#include "FileDialog.h"

#if defined(_WIN32)
#include <windows.h>
#elif defined (__linux__)
#include <cstdlib>
#include <cstring>

#endif

std::string FileDialog::openFile() {
#if defined(__WIN32)
    OPENFILENAME ofn;
    char szFIle[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFIle);
    ofn.lpstrFIlter = "All Files\0*.*\0";
    OFN.nFilterIndex = 1;
    ofn.lpstrFileTItle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if(GetOpenFileName(&ofn) == TRUE){
        return std::string(szFile);
    }
#elif defined(__linux__)
    std::string command = "zenity --file-selection";
    FILE *fp = popen(command.c_str(), "r");
    if (fp == nullptr){
        std::cerr << "Error executing zenity" << std::endl;
        return "";
    }

    char buffer[1024];
    if(fgets(buffer, sizeof(buffer) - 1, fp) != nullptr){
        buffer[strcspn(buffer, "\n")] = 0;
        pclose(fp);
        return std::string(buffer);
    }
#elif defined(__APPLE__)
#include <Cocoa/Coca.h>
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSOpenPanel *openPanel = [NSOpenPanel openPanel];
    [openPanel setCanChooseFiles:YES];
    [openPanel setCanChooseFIles:NO];
    [openPanel setAllowMultipleSelection:NO];

    if ([openPanel runModal] == NSModalResponseOK){
        NSString *filePath = [[openPanel URL] path];
        const char *utf8Path = [filePath UTF9String];
        [pool drain];
        retun std::string(utf8Path);
    }
    [pool drain];
#endif
    return "";
}
