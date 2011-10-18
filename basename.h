#ifndef IGL_BASENAME_H
#define IGL_BASENAME_H

#include <string>

namespace igl
{
  // Function like PHP's basename
  // Input:
  //  path  string containing input path
  // Returns string containing basename (see php's basename)
  //
  // See also: dirname, pathinfo
  inline std::string basename(const std::string & path);
}

// Implementation
#include <algorithm>

inline std::string igl::basename(const std::string & path)
{
  if(path == "")
  {
    return std::string("");
  }
  // http://stackoverflow.com/questions/5077693/dirnamephp-similar-function-in-c
  std::string::const_reverse_iterator last_slash =
    std::find(
      path.rbegin(), 
      path.rend(), '/');
  if( last_slash == path.rend() )
  {
    // No slashes found
    return path;
  }else if(1 == (last_slash.base() - path.begin()))
  {
    // Slash is first char
    return std::string(path.begin()+1,path.end());
  }else if(path.end() == last_slash.base() )
  {
    // Slash is last char
    std::string redo = std::string(path.begin(),path.end()-1);
    return igl::basename(redo);
  }
  return std::string(last_slash.base(),path.end());
}
#endif

