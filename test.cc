#include <sys/stat.h>

#include <iostream>
#include <bitset>
using namespace std;

#define FILEMODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH
#define DIRMODE S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IXOTH

int main()
{
    mode_t fm, dm;
    fm = FILEMODE;
    dm = DIRMODE;
    cout << sizeof(mode_t) << endl;
    cout << bitset<32>(fm) << endl;
    cout << bitset<32>(dm) << endl;
    cout << int(S_IRUSR) << endl;
    cout << bitset<32>(S_IRUSR) << endl;
    return 0;
}