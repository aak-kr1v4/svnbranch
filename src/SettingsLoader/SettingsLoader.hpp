#ifndef SETTINGS_LOADER_HPP
#define SETTINGS_LOADER_HPP

#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class SettingsLoader
{
public:

    explicit SettingsLoader(const std::string& filename);

public:
    bool        loadSettings();
    int         getRevisionNumber() const;
    std::string getTargetBranchUrl() const;
    std::string getNewPersonalBranchUrl() const;

private:

    bool isValidUrl(const std::string& url) const;

    template<typename T>
    T getSetting(const std::string& key) const
    {
        try
        {
            return readTree_.get<T>(key);
        }
        catch (const boost::property_tree::ptree_bad_path&)
        {
            std::cerr << "Setting not found: " << key << std::endl;

        }
        catch (const boost::property_tree::ptree_bad_data&)
        {
            std::cerr << "Incorrect data type for setting: " << key << std::endl;
        }
        return T();
    }
private:
    std::string filename_;
    boost::property_tree::ptree readTree_;
};

#endif
