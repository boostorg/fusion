#include <boost/config.hpp>

#if !defined(BOOST_NO_CXX11_HDR_TUPLE) && \
    !defined(BOOST_NO_CXX11_SMART_PTR)

#include <memory>
#include <tuple>
#include <boost/any.hpp>
#include <iostream>

namespace Core
{
    class AutoConverter
    {
        std::shared_ptr<boost::any> t_;

    public:
        AutoConverter(std::shared_ptr<boost::any> const & t)
            : t_(t)
        {}

        template <typename C>
        operator C ()
        {
            try
            {
                boost::any & a = (*t_);

                return boost::any_cast<C>(a);
            }
            catch(boost::bad_any_cast & e)
            {
                std::cerr << "Internal conversion bug: "
                          << "Failed to convert data holder to "
                          << typeid(C).name() << "\n"
                          << e.what()
                          << std::endl;

                C c = C();
                return c;
            }
        }
    };


    inline AutoConverter Demo()
    {
        std::shared_ptr<boost::any> p_result
            (new boost::any(std::make_tuple(1, 2, 3, 4)));
        return p_result;
    }

} // namespace Core


int main()
{
    std::tuple<int, int, int, int> test = Core::Demo();
    return 0;
}

#else

int main()
{
    return 0;
}

#endif

