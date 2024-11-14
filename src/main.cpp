#include "SettingsLoader/SettingsLoader.hpp"
#include "LogWrapper/LogWrapper.hpp"

int main() {

    LOG_INFO("Starting the program");
    LOG_ERROR("Some error message with arg: {}", 1);
    LOG_WARN("Easy padding in numbers like {:08d}", 12);
    LOG_CRITICAL("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    LOG_INFO("Support for floats {:03.2f}", 1.23456);
    LOG_INFO("Positional args are {1} {0}..", "too", "supported");
    LOG_INFO("{:<30}", "left aligned");

    SettingsLoader settings("settings.json");

    if (settings.loadSettings())
    {
        int revNumber = settings.getRevisionNumber();
        std::string targetBranchUrl = settings.getTargetBranchUrl();
        std::string newPersonalBranchUrl = settings.getNewPersonalBranchUrl();
        
        LOG_INFO("REVISION_NUMBER: {0:d}", revNumber);
        LOG_INFO("TARGET_BRANCH_URL: {}", targetBranchUrl);
        LOG_INFO("NEW_PERSONAL_BRANCH_URL: {}", newPersonalBranchUrl);
 
    }

    std::cin.get();

    return 0;
}
