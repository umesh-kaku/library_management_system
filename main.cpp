using namespace std;
#include "include/LibraryManagementSystem.h"
#include "include/LibraryDatabase.h"
int main() {
    LibraryDatabase database;
    LibraryManagementSystem library(&database);
    library.start_system();
    return 0;
}