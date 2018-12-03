/*
 * T.h
 *
 *  Created on: Dec 2, 2018
 *      Author: root
 */

#ifndef T_H_
#define T_H_

#include "Poco/JSON/JSON.h"
#include "Poco/JSON/Handler.h"
#include "Poco/JSONString.h"


#define BYTE unsigned char

using namespace std;
using namespace Poco::JSON;

namespace Poco {
namespace Util {

class T : public Handler{
public:
	string mystr;
	T();
	virtual ~T();
	virtual void resets() = 0;
protected:
	BYTE getByte(bool b);
private:
	string getStr(char c);
};

} /* namespace Util */
} /* namespace Poco */

#endif /* T_H_ */
