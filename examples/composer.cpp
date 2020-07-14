////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 Vladislav Trifochkin
//
// This file is part of [pfs-rfc5870](https://github.com/semenovf/pfs-rfc5870) library.
//
// Changelog:
//      2020.07.14 Initial version
////////////////////////////////////////////////////////////////////////////////
#include "pfs/rfc5870/composer.hpp"
#include <iostream>
#include <cstdlib>

#if defined(HAVE_QT5_CORE)
#   include "pfs/rfc5870/qt_suppl.hpp"
#endif

using std::cout;
namespace geo = pfs::rfc5870;

int main ()
{
    {
        geo::uri uri;
        uri.set_latitude(66.0f);
        uri.set_longitude(30.0f);
        uri.set_altitude(100.0f);
        uri.set_crs("ABC");
        uri.set_uncertainty(6.5f);
        uri.insert("foo", "val");
        uri.insert("bar");

        cout << uri << "\n";
    }

#if defined(HAVE_QT5_CORE)
    {
        geo::basic_uri<double, QString> uri;
        uri.set_latitude(66.0f);
        uri.set_longitude(30.0f);
        uri.set_altitude(100.0f);
        uri.set_crs("ABC");
        uri.set_uncertainty(6.5f);
        uri.insert("foo", "val");
        uri.insert("bar");

        cout << uri << "\n";
    }
#endif

    return EXIT_SUCCESS;
}
