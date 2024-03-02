//
// Created by cryptic on 02/03/24.
//

#ifndef INFERNOPLAYER_FILEDIALOG_H
#define INFERNOPLAYER_FILEDIALOG_H
#include <iostream>

class FileDialog {
public:
    FileDialog() = default;
    ~FileDialog() = default;

    std::string openFile();
};


#endif //INFERNOPLAYER_FILEDIALOG_H
