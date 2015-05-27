/*this Singleton class can not work at multiple threads environment*/
class Singleton {
public:
	static Singleton* GetInstance();

private:
	Singleton();
	static Singleton* instance;
};

Singleton* Singleton::instance = NULL;
Singleton* Singleton::GetInstance(){
	//in multiple threads environment,the 
	//codes below can not work well
	if(NULL == instance)    //competition condition
		instance = new Singleton;
	return instance;
}
