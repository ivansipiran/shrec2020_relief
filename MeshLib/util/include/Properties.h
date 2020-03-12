#ifndef __PROPERTIES_H_
#define __PROPERTIES_H_

#include <map>
#include <string>
#include "util_global.h"

namespace Util{

class UTIL_API Properties{
	private:
		std::map<std::string, std::string> propertyList;
		std::string trim(std::string& input);

	public:
		Properties() {}
		virtual ~Properties() {}

		void load(std::string filename);
		std::string getProperty(std::string property);
		void show();
};
}
#endif

