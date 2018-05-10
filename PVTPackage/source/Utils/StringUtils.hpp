#pragma once


#include "Assert.hpp"

// Std library includes
#include <sstream>
#include <vector>


namespace StringUtils
{

  ////Formatting
  void Trim(std::string& str);
  bool RemoveStringAndFollowingContentFromLine(std::string ToBeRemoved, std::string& line);
  std::string RemoveString(std::string ToBeRemoved, std::string data);
  void RemoveTab(std::vector<std::string>& v);
  void RemoveEndOfLine(std::vector<std::string>& v);
  void RemoveTab(std::string& v);
  void RemoveEndOfLine(std::string& v);
  void RemoveExtraSpaces(std::string& v);
  bool ExtendDefault(int n, std::string& v);

  ////Extraction
  std::string GetNthWord(int n, std::string data);

  ////Conversion
  //to Vector of scalar
  template<typename T>
  void VectorStringToVector(std::vector<std::string>& data, std::vector<T>& v)
  {
    ASSERT(data.size() == 1, " >> operator: incompatible origin and target");
    ASSERT(v.size() == 0, " Input vector must have 0 size");
    v.reserve(data[0].size());
    std::istringstream iss(data[0]);
    T sub;
    while (iss >> sub)
    {
      v.push_back(sub);
    }

  };

  //template<typename T>
  //void StringToVector(std::string& data, std::vector<T>& v)
  //{
  // 
  //  v.reserve(data.size());
  //  std::istringstream iss(data);
  //  T sub;
  //  while (iss >> sub)
  //  {
  //    v.push_back(sub);
  //  }

  //};

  template<typename T>
  void FromStringTo(std::string& data, std::vector<T>& v)
  {
    v.reserve(data.size());
    std::istringstream iss(data);
    T sub;
    while (iss >> sub)
    {
      v.push_back(sub);
    }
  };

  template<typename T>
  void FromStringTo(std::string& data, T& v)
  {
    std::istringstream iss(data);
    iss >> v;
  };



  template<typename T>
  void VectorStringToVectorChopped(int ChopSize, std::vector<std::string>& data, std::vector<std::vector<T>>& v)
  {
    int mdataSize(int(data.size()));
    ASSERT(mdataSize == 1, " >> operator: incompatible origin and target");
    v.reserve(data[0].size() / (2 * ChopSize));
    std::istringstream iss(data[0]);
    T sub;
    std::vector<T> sline(ChopSize);
    int cpt = 0;
    while (iss >> sub)
    {
      cpt++;
      sline[cpt-1] = sub;
      if (cpt%ChopSize == 0)
      {
        v.push_back(sline);
        cpt = 0;
      }
    }
  ASSERT(cpt == 0, " Data size must be a multiple of ChopSize");
  };



};
