#include "SettingsLoader.hpp"
#include <fstream>
#include <boost/regex.hpp>

SettingsLoader::SettingsLoader(const std::string& fileName) : filename_(fileName) {};

int SettingsLoader::getRevisionNumber() const
{
    return getSetting<int>("REVISION_NUMBER");
}

std::string SettingsLoader::getTargetBranchUrl() const
{
    auto url = getSetting<std::string>("TARGET_BRANCH_URL");

    if (isValidUrl(url))
    {
        return url;
    }
    else
    {
        return "";
    }
}

std::string SettingsLoader::getNewPersonalBranchUrl() const
{
    auto url = getSetting<std::string>("NEW_PERSONAL_BRANCH_URL");

    if (isValidUrl(url))
    {
        return url;
    }
    else
    {
        return "";
    }
}

bool SettingsLoader::isValidUrl(const std::string& url) const
{
    try
    {
        static const boost::regex urlRegex(R"((https|http|svn)(:\/\/)([a-zA-Z0-9_-]+[\/]?)*)",
            boost::regex::icase
        );

        return boost::regex_match(url, urlRegex);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
        std::cin.get();
        return false;
    }
}

bool SettingsLoader::loadSettings()
{
    std::ifstream inFile(filename_);
    if (!inFile.is_open())
    {
        std::cerr << "Cannot find or open " << filename_ << std::endl;
        return false;
    }

    try
    {
        boost::property_tree::read_json(inFile, readTree_);
        inFile.close();
    }
    catch (const boost::property_tree::json_parser_error& ex)
    {
        std::cerr << "Error parsing JSON file: " << ex.what() << std::endl;
        return false;
    }

    return true;
}
