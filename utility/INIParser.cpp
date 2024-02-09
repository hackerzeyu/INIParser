#include "INIParser.h"
using namespace zeyu::utility;

INIParser::INIParser(const char *fileName):m_fileName(fileName)
{
    load(fileName);
}

void INIParser::load(const char *fileName)
{
    m_section.clear();
    m_fileName=fileName;
    ifs.open(fileName);
    if(ifs.fail())
        throw std::logic_error("file not exists or open failed:"+m_fileName);
    string line;
    string name;
    while (std::getline(ifs,line))
    {
        trim(line);
        if(line.empty())
        {
            continue;
        }
        else if(line[0]=='#')    //注释行
        {
            continue;
        }
        else if(line[0]=='[')    //区域行
        {
            auto pos=line.find(']');
            if(pos==string::npos)
            {
                throw std::logic_error("no matching ] in section");
            }
            name= line.substr(1,pos-1);
            trim(name);
            m_section.insert(std::make_pair(name,Section()));
        }
        else    //键值对
        {
            auto pos=line.find('=');
            if(pos==string::npos)
            {
                throw std::logic_error("Invalid line:"+line);
            }
            string item=line.substr(0,pos);
            trim(item);
            string val=line.substr(pos+1);
            trim(val);
            m_section[name][item]=val;
        }
    }
    ifs.close();
}

string& INIParser::trim(string &s)
{
    if (s.empty())
        return s;
    s.erase(0,s.find_first_not_of(" \r\n"));
    s.erase(s.find_last_not_of(" \r\n")+1);
    return s;
}

string INIParser::str() const
{
    std::stringstream ss;
    for(auto it=m_section.begin();it!=m_section.end();it++)
    {
        ss<<"["<<it->first<<"]"<<std::endl;
        for(auto iter=it->second.begin();iter!=it->second.end();iter++)
        {
            ss<<iter->first<<" = "<<iter->second<<std::endl;
        }
        ss<<std::endl;
    }
    return ss.str();
}

void INIParser::show() const
{
    std::cout<<str();
}

void INIParser::set(const string &section, const string &key, const Value &v)
{
    m_section[section][key]=v;
}

void INIParser::set(const string &section)
{
    m_section[section]=Section();
}

Value &INIParser::get(const string &section,const string& key)
{
    return m_section[section][key];
}

void INIParser::remove(const string &section)
{
    m_section.erase(section);
}

void INIParser::remove(const string &section, const string &key)
{
    auto it=m_section.find(section);
    if(it==m_section.end())
        return;
    m_section[section].erase(key);
}

void INIParser::update()
{
    std::ofstream ofs;
    ofs.open(m_fileName);
    if(ofs.fail())
    {
        throw std::logic_error("write file:"+m_fileName+"failed");
    }
    ofs<<str();
    ofs.close();
}

bool INIParser::has(const string &section)
{
    return m_section.find(section)!=m_section.end();
}

bool INIParser::has(const string &section, const string &key)
{
    auto it=m_section.find(section);
    if(it==m_section.end())
        return false;
    return it->second.find(key)!=it->second.end();
}





