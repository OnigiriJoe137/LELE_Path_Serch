// LELE_Path_Serch.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <boost/version.hpp>


int main()
{
	std::cout <<(BOOST_VERSION / 100000) << "." << (BOOST_VERSION / 100 % 1000) << "." << (BOOST_VERSION % 100) << std::endl;
	getchar();

    return 0;
}

