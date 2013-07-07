Boost.Fusion extension for std::array
=====================================

An attempt to adapt ```std::array``` for Boost.Fusion.

The implementation is functional and passes the same test as adapted Boost.Array.

Proposal thread on the Boost mailing list: 
[[fusion] Adapter for std::array](http://lists.boost.org/Archives/boost/2013/07/205045.php).

However, there is a problem with ADL and range-based access to the sequence
which is a well-known issue:

* [Fusion begin/end ADL issues with C++0x range-based for](http://lists.boost.org/Archives/boost/2010/12/index.php)
* Boost ticket: [fusion::begin and fusion::end lead to problems with ADL-based begin and end functions for ranges](https://svn.boost.org/trac/boost/ticket/4028)
* Boost ticket: [Treat std::array as a Fusion sequence](https://svn.boost.org/trac/boost/ticket/8241)

See also:

* N3257=11-0027 Jonathan Wakely and Bjarne Stroustrup: 
[Range-based for statements and ADL](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3257.pdf). 
Option 5 was chosen for C++11.

* [Jonathan Wakely's review](http://lists.boost.org/Archives/boost/2013/07/205064.php) of the issue regarding the Boost.Fusion adaptor for ```std::string```:
  > The standard was changed to *not* use unqualified begin/end when the type has begin/end members, because 
when there are multiple "greedy" overloads that can be found by ADL there is no simple way to prevent ambiguity. So I agree that your 
best option might be to avoid those unqualified calls. 
