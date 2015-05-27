/*this Singleton class can work well at multiple threads environment*/
class Singleton{
private:
	Singleton();
	static Singleton* instance;

public:
	static Singleton* GetInstance();
};

Singleton* Singleton::instance = new Singleton;

Singleton* Singleton::GetInstance(){
	return instance;
}
