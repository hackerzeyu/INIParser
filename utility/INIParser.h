#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <sstream>
using std::string;

#include "Value.h"

namespace zeyu
{
    namespace utility
    {
        class INIParser
        {
        public:
            typedef std::map<string, Value> Section;
        public:
            INIParser() = default;
            ~INIParser() = default;
            INIParser(const char *fileName);    //加载文件数据
            void load(const char *fileName);    //加载文件数据
            void update();                      //更新文件数据
            string str() const;
            void show() const;
            bool has(const string& section);
            bool has(const string& section,const string& key);
            void set(const string& section);
            void set(const string& section,const string& key,const Value& v);   //设置键值
            Value& get(const string& section,const string& key);
            void remove(const string& section);
            void remove(const string& section,const string& key);
        public:
            Section& operator[](const string& section)
            {
                return m_section[section];
            }
        private:
            string& trim(string &s);            //内部函数,删除左右多余字符s
        private:
            std::map<string, Section> m_section;    //区间映射
            std::ifstream ifs;
            string m_fileName;                      //文件名
        };
    }
}