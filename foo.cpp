#include <stdlib.h>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <cstdint>

static std::string make_num_str(const int32_t count)
{
    int32_t sNum = rand() % static_cast<int32_t>(count * 0.7);
    return std::to_string(sNum);
}

template <typename set_t>
static void test_set_try_emplace(int32_t count)
{
    set_t sSet;

    for (int32_t i = 0; i < count; i++)
    {
        std::string sStr{make_num_str(count)};
        if (sSet.count(sStr) == 0)
        {
            sSet.emplace(std::move(sStr));
        }
        else
        {
            continue;
        }
    }
}

template <typename set_t>
static void test_set_emplace(int32_t count)
{
    set_t sSet;

    for (int32_t i = 0; i < count; i++)
    {
        std::string sStr{make_num_str(count)};
        sSet.emplace(std::move(sStr));
    }
}

template <typename map_t>
static void test_map_try_emplace(int32_t count)
{
    map_t sMap;

    for (int32_t i = 0; i < count; i++)
    {
        std::string sStr{make_num_str(count)};
        sMap.try_emplace(std::move(sStr), 1);
    }
}

template <typename map_t>
static void test_map_emplace(int32_t count)
{
    map_t sMap;

    for (int32_t i = 0; i < count; i++)
    {
        std::string sStr{make_num_str(count)};
        sMap.emplace(std::move(sStr), 1);
    }
}

int32_t main(int32_t argc, char* argv[])
{
    srand(time(nullptr));

    std::string_view sContainer{argv[1]};
    std::string_view sMethod{argv[2]};
    int32_t sCount = std::stoi(argv[3]);

    if (sMethod == "emplace")
    {
        if (sContainer == "set")
        {
            test_set_emplace<std::set<std::string>>(sCount);
        }
        else if (sContainer == "unordered_set")
        {
            test_set_emplace<std::unordered_set<std::string>>(sCount);
        }
        else if (sContainer == "map")
        {
            test_map_emplace<std::map<std::string, int32_t>>(sCount);
        }
        else if (sContainer == "unordered_map")
        {
            test_map_emplace<std::unordered_map<std::string, int32_t>>(sCount);
        }
        else
        {
            std::cerr << "Unknown container: " << sContainer << "\n";
            exit(1);
        }
    }
    else if (sMethod == "try_emplace")
    {
        if (sContainer == "set")
        {
            test_set_try_emplace<std::set<std::string>>(sCount);
        }
        else if (sContainer == "unordered_set")
        {
            test_set_try_emplace<std::unordered_set<std::string>>(sCount);
        }
        else if (sContainer == "map")
        {
            test_map_try_emplace<std::map<std::string, int32_t>>(sCount);
        }
        else if (sContainer == "unordered_map")
        {
            test_map_try_emplace<std::unordered_map<std::string, int32_t>>(sCount);
        }
        else
        {
            std::cerr << "Unknown container: " << sContainer << "\n";
            exit(1);
        }
    }
    else
    {
        std::cerr << "Unknown method: " << sMethod << "\n";
        exit(1);
    }

    return 0;
}
