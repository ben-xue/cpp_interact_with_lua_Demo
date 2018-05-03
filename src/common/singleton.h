#include "nonecopyable.h"

template<typename className>
class singleton : public nonecopyable{
public:
	static className& Instance()
	{
		static className obj;
		return obj;
	}
};