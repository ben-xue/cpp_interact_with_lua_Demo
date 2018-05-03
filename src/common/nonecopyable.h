#ifndef NONECOPYABLE_H_
#define NOECOPYABLE_H_

class nonecopyable{

protected:
	nonecopyable() {}
	~nonecopyable() {}

#if __cplusplus < 201103l
	private:
		nonecopyable(const nonecopyable& );
		nonecopyable& operator=(const nonecopyable& );
#else
	public:
		nonecopyable(const nonecopyable&) = delete;
		nonecopyable& operator=(const nonecopyable&) = delete;
#endif
		
};

#endif