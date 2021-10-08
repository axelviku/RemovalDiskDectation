#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

std::string allDrives;

char getRemovableDisk();

int main(void) {
    char driveLetter = getRemovableDisk();
    
    while (1) {
    
        driveLetter = getRemovableDisk();
        if (driveLetter != '0') {
            printf("test %c \n", driveLetter);
        }
        else
        {
        	//	printf("%c \n", driveLetter);
        }

        Sleep(1000);
    }
    

    return 0;
}

char getRemovableDisk() {
    char drive = '0';

    char szLogicalDrives[MAX_PATH];
    DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);

    string currentDrives = "";
	//printf("%d \n", dwResult);
   // std::cout << dwResult << endl;
    for (int i = 0; i < dwResult; i++) {
  	
        if (szLogicalDrives[i] > 64 && szLogicalDrives[i] < 90) {
            currentDrives.append(1, szLogicalDrives[i]);
            //	printf("logical drive %d %d \n", i,szLogicalDrives[i]);
            if (szLogicalDrives[i]==68)
            {
            	printf("DD \n");
            	szLogicalDrives[i]=101;
            }
            if (allDrives.find(szLogicalDrives[i]) > 100) {
            	    drive = szLogicalDrives[i];
            }

        }
    }

    allDrives = currentDrives;

    return drive;
}
