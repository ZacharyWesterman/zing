#pragma once
#ifndef LIST_FILES_IN_DIR_H_INCLUDED
#define LIST_FILES_IN_DIR_H_INCLUDED

#include "../core/string.h"
#include "../core/array.h"

#ifdef __linux__
    #error "list_files_in_dir.h" is incompatible with Linux.
#elif _WIN32

#include <windows.h>

namespace file
{
    void list_files_in_dir(const core::string<char>& dir,
                           const core::string<char>& file_type,
                           core::array< core::string<char> >& output)
    {
        core::string<char> search_path = dir;
        search_path += "/*.";
        search_path += file_type;


        WIN32_FIND_DATA fd;
        HANDLE hFind = FindFirstFile(search_path.str(), &fd);

        if (hFind != INVALID_HANDLE_VALUE)
        {
            do
            {
                if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                {
                    output.add(core::string<char>(fd.cFileName));
                }
            }
            while (FindNextFile(hFind, &fd));

            FindClose(hFind);
        }
    }
}

#else
    #error "list_files_in_dir.h" is incompatible with target OS.
#endif

#endif // LIST_FILES_IN_DIR_H_INCLUDED