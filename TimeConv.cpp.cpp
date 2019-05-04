
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <vector>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <cmath>
#include <map>


std::string toString( long value )
{
	std::stringstream literal_value;
	literal_value << value;
	return literal_value.str();
}
std::string getLiteralTime( long seconds )
{
	long days = seconds / 86400;
	//
	seconds %= 86400;
	//
	long hours = seconds / 3600;
	//
	seconds %= 3600;
	//
	long minutes = seconds / 60;
	//
	seconds %= 60;
	//
	std::stringstream literal_time;
	literal_time << ( days ? toString( days ) : "" ) << ( days ? "d" : "" ) << ( hours ? toString( hours ) : "" ) << ( hours ? "h" : "" ) << ( minutes ? toString( minutes ) : "" ) << ( minutes ? "m" : "" ) << ( seconds ? toString( seconds ) : "" ) << ( seconds ? "s" : "" );
	return literal_time.str().c_str();
}
long getLongTime( std::string time )
{
	long days, hours, minutes, seconds;
	days = hours = minutes = seconds = -1;
	//
	unsigned int days_index = time.find( "d" );
	if( days_index == std::string::npos )
		days = 0;
	//
	unsigned int hours_index = time.find( "h" );
	if( hours_index == std::string::npos )
		hours = 0;
	//
	unsigned int minutes_index = time.find( "m" );
	if( minutes_index == std::string::npos )
		minutes = 0;
	//
	unsigned int seconds_index = time.find( "s" );
	if( seconds_index == std::string::npos )
		seconds = 0;
	//
	std::string str_days, str_hours, str_minutes, str_seconds;
	//
	if( !days && !hours && !minutes )
	{
		str_seconds = time.substr( 0, seconds_index );
	}
	else if( !days && !hours )
	{
		str_minutes = time.substr( 0, minutes_index );
		str_seconds = time.substr( minutes_index + 1, seconds_index - minutes_index - 1 );
	}
	else if( !days && !minutes )
	{
		str_hours = time.substr( 0, hours_index );
		str_seconds = time.substr( hours_index + 1, seconds_index - hours_index - 1 );
	}
	else if( !hours && !minutes )
	{
		str_days = time.substr( 0, days_index );
		str_seconds = time.substr( days_index + 1, seconds_index - days_index - 1 );
	}
	else if( !days )
	{
		str_hours = time.substr( 0, hours_index );
		str_minutes = time.substr( hours_index + 1, minutes_index - hours_index - 1 );
		str_seconds = time.substr( minutes_index + 1, seconds_index - minutes_index - 1 );
	}
	else if( !hours )
	{
		str_days = time.substr( 0, days_index );
		str_minutes = time.substr( days_index + 1, minutes_index - days_index - 1 );
		str_seconds = time.substr( minutes_index + 1, seconds_index - minutes_index - 1 );
	}
	else if( !minutes )
	{
		str_days = time.substr( 0, days_index );
		str_hours = time.substr( days_index + 1, hours_index - days_index - 1 );
		str_seconds = time.substr( hours_index + 1, seconds_index - hours_index - 1 );
	}
	else
	{
		str_days = time.substr( 0, days_index );
		str_hours = time.substr( days_index + 1, hours_index - days_index - 1 );
		str_minutes = time.substr( hours_index + 1, minutes_index - hours_index - 1 );
		str_seconds = time.substr( minutes_index + 1, seconds_index - minutes_index - 1 );
	}
	//
	return atoi( str_days.c_str() ) * 86400 +
			atoi( str_hours.c_str() ) * 3600 +
			atoi( str_minutes.c_str() ) * 60 +
			atoi( str_seconds.c_str() );
}
//
int main( int argc, char ** argv )
{
	if( toString( atoi( argv[ 1 ] ) ).size() == strlen( argv[ 1 ] ) )
		std::cout << getLiteralTime( atoi( argv[ 1 ] ) ) << std::endl;
	else
		std::cout << getLongTime( argv[ 1 ] ) << std::endl;
}

