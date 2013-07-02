Boost.Fusion extension for std::array
=====================================

An attempt to adapt ```std::array``` for Boost.Fusion.

The implementation is functional and passes the same test as  adapted Boost.Array.

However, there is a problem with ADL and range-based access to the sequence
which is a well-known issue:

* [Fusion begin/end ADL issues with C++0x range-based for](http://lists.boost.org/Archives/boost/2010/12/index.php)
* Boost ticket: [fusion::begin and fusion::end lead to problems with ADL-based begin and end functions for ranges](https://svn.boost.org/trac/boost/ticket/4028)
* Boost ticket: [Treat std::array as a Fusion sequence](https://svn.boost.org/trac/boost/ticket/8241)
