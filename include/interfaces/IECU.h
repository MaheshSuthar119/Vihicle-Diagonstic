#include <string>
class IECU
{
public:

    virtual void initialize() = 0;

    virtual void update() = 0;

    virtual void shutdown() = 0;

    virtual void printStatus() const = 0;

    virtual std::string getName() const = 0;

    virtual ~IECU() = default;
};