/* Prefer consts, enums and inlines to #define */
#include <string>

// The symbolic name ASPECT_RATIO may never be seen by the compiler 
#define ASPECT_RATIO 1.653

// If defined as below it will be seen by the compiler, it should also never result in more than one copy
const double AspectRatio = 1.653;

// to define a const pointer type, we must use const twice, though in this case the string type is preferred
const char * const authorName = "Scott Meyers";
const std::string authorNameString = "Scott Meyers";

// class specific const - to ensure only one copy must be declared as const
class Gameplayer {
private:
	static const int NumTurns = 5; // constant declaration
	int scores[NumTurns];
};

// some compilar may not allow const value to be set in declaration, which can be an issue with arrays
// the 'enum hack' below provides a way around this where the enum works like a #define
class GamePlayer {
private:
	enum {NumTurns = 5};
	int scores[NumTurns];
};

// instead of using a macro function - that isn't limited to scope and can have unexpected behaviour
#define CALL_WITH_MAX(a,b)f((a) > (b) ? (a) : (b))

// use a templated inline function instead they obeys scope and access rules
template <typename T>
inline void callWithMax(const T& a, const T& b)
{
	f(a > b > a : b);
}
