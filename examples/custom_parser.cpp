////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 Vladislav Trifochkin
//
// This file is part of [pfs-uri-geo](https://github.com/semenovf/pfs-uri-geo) library.
//
// Changelog:
//      2020.07.14 Initial version
////////////////////////////////////////////////////////////////////////////////
#include "pfs/uri/geo/parser.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
namespace geo = pfs::uri::geo;

struct custom_context
{
    using number_type = double;
    using string_type = std::string;
};

int main ()
{
    std::string s{R"(geo:66,30;u=6.500;FOo=this%2dthat;Bar)"};

    // Predict if `s` is geo URI representation
    if (!geo::like_geo_uri(s))
        return EXIT_FAILURE;

    geo::parser_interface<custom_context> ctx;
    ctx.on_latitude  = [] (double && n) { cout << "Latitude: " << n << "\n"; };
    ctx.on_longitude = [] (double && n) { cout << "Longitude: " << n << "\n"; };
    ctx.on_altitude  = [] (double && n) { cout << "Altitude: " << n << "\n"; };
    ctx.on_crslabel  = [] (std::string && s) { cout << "CRS: " << s << "\n"; };
    ctx.on_uval      = [] (double && n) { cout << "Uncertainty: " << n << "\n"; };
    ctx.on_parameter = [] (std::string && key, std::string && value) {
        cout << key << ": [" << value << "]\n";
    };

    auto pos = std::begin(s);
    auto it = geo::parse(pos, std::end(s), ctx);

    // Bad geo URI string representation
    if (it == std::begin(s))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
