/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/
namespace boost { namespace fusion
{
    struct void_;
    struct fusion_sequence_tag;
    template <typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9>
    struct map : sequence_base<map<T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9> >
    {
        struct category : random_access_traversal_tag, associative_tag {};
        typedef map_tag fusion_tag;
        typedef fusion_sequence_tag tag; 
        typedef mpl::false_ is_view;
        typedef vector<
            T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9>
        storage_type;
        typedef typename storage_type::size size;
        BOOST_FUSION_GPU_ENABLED
        map()
            : data() {}
        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        map(Sequence const& rhs)
            : data(rhs) {}
    BOOST_FUSION_GPU_ENABLED
    explicit
    map(T0 const& arg0)
        : data(arg0) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1)
        : data(arg0 , arg1) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2)
        : data(arg0 , arg1 , arg2) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3)
        : data(arg0 , arg1 , arg2 , arg3) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3 , T4 const& arg4)
        : data(arg0 , arg1 , arg2 , arg3 , arg4) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3 , T4 const& arg4 , T5 const& arg5)
        : data(arg0 , arg1 , arg2 , arg3 , arg4 , arg5) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3 , T4 const& arg4 , T5 const& arg5 , T6 const& arg6)
        : data(arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3 , T4 const& arg4 , T5 const& arg5 , T6 const& arg6 , T7 const& arg7)
        : data(arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , arg7) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3 , T4 const& arg4 , T5 const& arg5 , T6 const& arg6 , T7 const& arg7 , T8 const& arg8)
        : data(arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , arg7 , arg8) {}
    BOOST_FUSION_GPU_ENABLED
    map(T0 const& arg0 , T1 const& arg1 , T2 const& arg2 , T3 const& arg3 , T4 const& arg4 , T5 const& arg5 , T6 const& arg6 , T7 const& arg7 , T8 const& arg8 , T9 const& arg9)
        : data(arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , arg7 , arg8 , arg9) {}
        template <typename T>
        BOOST_FUSION_GPU_ENABLED
        map& operator=(T const& rhs)
        {
            data = rhs;
            return *this;
        }
        BOOST_FUSION_GPU_ENABLED
        map& operator=(map const& rhs)
        {
            data = rhs.data;
            return *this;
        }
        BOOST_FUSION_GPU_ENABLED
        storage_type& get_data() { return data; }
        BOOST_FUSION_GPU_ENABLED
        storage_type const& get_data() const { return data; }
    private:
        storage_type data;
    };
}}
