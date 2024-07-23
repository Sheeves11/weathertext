#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "gethttp.h"
#include <exception>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>


using namespace std;

string get_http(const string &server,const string &path);
string getQuery(const string, stringstream&);
void artWork(const string);

int main(int argc, char *argv[]){
	using namespace boost::property_tree;
	stringstream temp;
	stringstream forecast;

	string timeQuery("\"observation_time\":\"");
	string time;
	string weatherQuery ("\"weather\":\"");
	string weather;
	string fullQuery ("\"full\":\"");
	string full;
	string temperatureQuery("\"temperature_string\":\"");
	string temperature;
	string windQuery("\"wind_string\":\"");
	string wind;

	string dayQuery("\"title\":\"");
	string day;
	string forecastQuery("\"fcttext\":\"");
	string forecastString;

	string addressHalf = "/api/161ca0a756e8d92c/conditions/q/";
	string addressForcast = "/api/161ca0a756e8d92c/forecast/q/";
	string addressHalfTwo = ".json";
	string zipcode = "72801";
	string fullAddress;
	string forecastAddress;

	string line ("    |--------------------------------------------------------------|");

	cout << endl << endl << endl;

	if ( argc == 2 ){
		zipcode = argv[1];
	}
	else if (argc == 1){		
		cout << "\t" << "Enter a Zipcode: ";
		cin >> zipcode;
	}
	else{
		cout << "Usage: weathertext <zipcode>" << endl;
		return 0;
	}

	
	//create the required url addresses
	fullAddress.append(addressHalf);
	fullAddress.append(zipcode);
	fullAddress.append(addressHalfTwo);
	forecastAddress.append(addressForcast);
	forecastAddress.append(zipcode);
	forecastAddress.append(addressHalfTwo);

	//call the get page function
	temp << get_http("api.wunderground.com",fullAddress);
	forecast << get_http("api.wunderground.com",forecastAddress);

	//parse the .json results
	time=getQuery(timeQuery, temp);
	weather=getQuery(weatherQuery, temp);
	full=getQuery(fullQuery, temp);
	temperature=getQuery(temperatureQuery, temp);
	wind=getQuery(windQuery, temp);
	day=getQuery(dayQuery, forecast);
	forecastString=getQuery(forecastQuery, forecast);

	//formatted output
	/*	
	cout <<
    "\n\t       ___(                  )"<<
    "\n\t      (       Weather Text      _)"<<
    "\n\t     (_        By: Sheeves   __))"<<
    "\n\t       ((             _____)"<<
    "\n\t         (________)----'"<<
    "\n\t            _/  /"<<
    "\n\t           / _/"<<
    "\n\t         _/ /"<<
    "\n\t        / _/"<<
    "\n\t      _//"<<
    "\n\t     /_/"<<
    "\n\t    //"<<
    "\n\t   /' ";
	*/
	
	cout << endl << endl << "\t\t" <<
	time <<
		endl << "\t\t" <<
		endl << "\t\t" <<
	"Weather Conditions for " << full <<
		endl << 
	line <<
		endl <<
		endl << "\t\t" <<
	"Current Conditions: " << weather <<
		endl << "\t\t" <<
	"Temperature: " << temperature <<
		endl << "\t\t" <<
	"Wind: " << wind <<
		endl <<
		endl <<
		line <<
		endl <<
		endl << "\t\t" <<
	day << "'s Forcast is :" << 
		endl << 
		endl << "\t\t" <<
	forecastString <<
		endl <<
		endl <<
	line <<
		endl <<
		endl;
	/*
	artWork(weather);
		cout << endl <<
	line << endl;
	*/

	return 0;
}

string getQuery(string query, stringstream &temp){
	int found = temp.str().find(query);
	if (found!=std::string::npos){}
	else{
		cout << "\nQuery: " << query << "not found!";
	}
	string result;
	std::stringstream queryResult;
	int count = 0;
	for(int i=found+(query.size()); i<(found+200); ++i){
		count ++;
		if(count > 40 && temp.str().at(i) == ' '){
			queryResult << "\n\t\t";
			count = 0;
		}
		else if(temp.str().at(i)=='"'){
			//cout << "I found the \" at: " << i << endl;
			i=found+300;
		}
		else{
			//cout << i << ": " << temp.str().at(i) << endl;
			queryResult << temp.str().at(i);
		}
	 }

	result = queryResult.str();

	return(result);
}

void artWork(string weather){
	if(weather=="Clear"){
	}

	if(weather=="Cloudy"){
		cout <<
			"\n\t			                _" <<
			"\n\t              (`  ).                   _" <<
			"\n\t             (     ).              .:(`  )`." <<
			"\n\t)           _(       '`.          :(   .    )" <<
			"\n\t        .=(`(      .   )     .--  `.  (    ) )" <<
			"\n\t       ((    (..__.:'-'   .+(   )   ` _`  ) )" <<
			"\n\t`.     `(       ) )       (   .  )     (   )  ._" <<
			"\n\t  )      ` __.:'   )     (   (   ))     `-'.-(`  )" <<
			"\n\t)  )  ( )       --'       `- __.'         :(      ))" <<
			"\n\t.-'  (_.'          .')                    `(    )  ))" <<
			"\n\t                  (_  )                     ` __.:'" <<
			"\n\t" <<
			"\n\t--..,___.--,--'`,---..-.--+--.,,-,,..._.--..-._.-a:f--." <<
			"\n\t";

			cout << endl;
	}

	if(weather=="Flurries"){
	}

	if(weather=="Fog"){
	}

	if(weather=="Haze"){
	}

	if(weather=="Mostly Cloudy"){
		cout <<
			"\n\t			                _" <<
			"\n\t              (`  ).                   _" <<
			"\n\t             (     ).              .:(`  )`." <<
			"\n\t)           _(       '`.          :(   .    )" <<
			"\n\t        .=(`(      .   )     .--  `.  (    ) )" <<
			"\n\t       ((    (..__.:'-'   .+(   )   ` _`  ) )" <<
			"\n\t`.     `(       ) )       (   .  )     (   )  ._" <<
			"\n\t  )      ` __.:'   )     (   (   ))     `-'.-(`  )" <<
			"\n\t)  )  ( )       --'       `- __.'         :(      ))" <<
			"\n\t.-'  (_.'          .')                    `(    )  ))" <<
			"\n\t                  (_  )                     ` __.:'" <<
			"\n\t" <<
			"\n\t--..,___.--,--'`,---..-.--+--.,,-,,..._.--..-._.-a:f--." <<
			"\n\t";

			cout << endl;
	}

	if(weather=="Mostly Sunny"){
	}

	if(weather=="Partly Cloudy"){
		cout <<
			"\n\t              ." <<
			"\n\t               					" <<
			"\n\t              |					" <<
			"\n\t     .               /				" <<
			"\n\t      \       I     				" <<
			"\n\t                  /" <<
			"\n\t        \  ,g88R_" <<
			"\n\t          d888(`  ).                   _" <<
			"\n\t -  --==  888(     ).=--           .+(`  )`." <<
			"\n\t)         Y8P(       '`.          :(   .    )" <<
			"\n\t        .+(`(      .   )     .--  `.  (    ) )" <<
			"\n\t       ((    (..__.:'-'   .=(   )   ` _`  ) )" <<
			"\n\t`.     `(       ) )       (   .  )     (   )  ._" <<
			"\n\t  )      ` __.:'   )     (   (   ))     `-'.:(`  )" <<
			"\n\t)  )  ( )       --'       `- __.'         :(      ))" <<
			"\n\t.-'  (_.'          .')                    `(    )  ))" <<
			"\n\t                  (_  )                     ` __.:'" <<
			"\n\t                                        	" <<
			"\n\t--..,___.--,--'`,---..-.--+--.,,-,,..._.--..-._.-a:f--.";
			cout << endl;
	}

	if(weather=="Partly Sunny"){
		cout <<
			"\n\t              ." <<
			"\n\t               					" <<
			"\n\t              |					" <<
			"\n\t     .               /				" <<
			"\n\t      \       I     				" <<
			"\n\t                  /" <<
			"\n\t        \  ,g88R_" <<
			"\n\t          d888(`  ).                   _" <<
			"\n\t -  --==  888(     ).=--           .+(`  )`." <<
			"\n\t)         Y8P(       '`.          :(   .    )" <<
			"\n\t        .+(`(      .   )     .--  `.  (    ) )" <<
			"\n\t       ((    (..__.:'-'   .=(   )   ` _`  ) )" <<
			"\n\t`.     `(       ) )       (   .  )     (   )  ._" <<
			"\n\t  )      ` __.:'   )     (   (   ))     `-'.:(`  )" <<
			"\n\t)  )  ( )       --'       `- __.'         :(      ))" <<
			"\n\t.-'  (_.'          .')                    `(    )  ))" <<
			"\n\t                  (_  )                     ` __.:'" <<
			"\n\t                                        	" <<
			"\n\t--..,___.--,--'`,---..-.--+--.,,-,,..._.--..-._.-a:f--.";
			cout << endl;
	}

	if(weather=="Freezing Rain"){
	}

	if(weather=="Rain"){
		cout <<			
			"\n\t        ------               _____" <<
			"\n\t       /      \ ___\     ___/    ___" <<
			"\n\t    --/-  ___  /    \/  /  /    /   \\" <<
			"\n\t   /     /           \__     //_     \\" <<
			"\n\t  /                     \   / ___     |" <<
			"\n\t  |           ___       \/+--/        /" <<
			"\n\t   \__           \       \           /" <<
			"\n\t      \__                 |          /     " <<
			"\n\t     \     /____      /  /       |   /     " <<
			"\n\t      _____/         ___       \/  /\      " <<
			"\n\t           \__      /      /    |    |     " <<
			"\n\t         /    \____/   \       /   //      " <<
			"\n\t     // / / // / /\    /-_-/\//-__-        " <<
			"\n\t      /  /  // /   \__// / / /  //" <<
			"\n\t     //   / /   //   /  // / // /" <<
			"\n\t      /// // / /   /  //  / //" <<
			"\n\t   //   //       //  /  // / /" <<
			"\n\t     / / / / /     /  /    /" <<
			"\n\t  ///  / / /  //  // /  // //" <<
			"\n\t     ///    /    /    / / / /" <<
			"\n\t///  /    // / /  // / / /  /" <<
			"\n\t   // ///   /      /// / /" <<
			cout << endl;
	}

	if(weather=="Sleet"){
	}

	if(weather=="Snow"){
	}

	if(weather=="Sunny"){
	}

	if(weather=="Thunderstorms"){
		cout <<
			"\n\t`--- `__'   `--'" <<
			"\n\t  `--' \ `---'" <<
			"\n\t     `--\-'" <<
			"\n\t        /" <<
			"\n\t       /" <<
			"\n\t      / \\" <<
			"\n\t      \  \\" <<
			"\n\t      /   \\" <<
			"\n\t     /   / \\" <<
			"\n\t '`'^^'\"^^'^^\"`\"";
			cout << endl;
	}

	if(weather=="Thunderstorm"){
			cout <<
			"\n\t`--- `__'   `--'" <<
			"\n\t  `--' \ `---'" <<
			"\n\t     `--\-'" <<
			"\n\t        /" <<
			"\n\t       /" <<
			"\n\t      / \\" <<
			"\n\t      \  \\" <<
			"\n\t      /   \\" <<
			"\n\t     /   / \\" <<
			"\n\t '`'^^'\"^^'^^\"`\"";
			cout << endl;
	}

	if(weather=="Overcast"){
		cout <<
			"\n\t			                _" <<
			"\n\t              (`  ).                   _" <<
			"\n\t             (     ).              .:(`  )`." <<
			"\n\t)           _(       '`.          :(   .    )" <<
			"\n\t        .=(`(      .   )     .--  `.  (    ) )" <<
			"\n\t       ((    (..__.:'-'   .+(   )   ` _`  ) )" <<
			"\n\t`.     `(       ) )       (   .  )     (   )  ._" <<
			"\n\t  )      ` __.:'   )     (   (   ))     `-'.-(`  )" <<
			"\n\t)  )  ( )       --'       `- __.'         :(      ))" <<
			"\n\t.-'  (_.'          .')                    `(    )  ))" <<
			"\n\t                  (_  )                     ` __.:'" <<
			"\n\t" <<
			"\n\t--..,___.--,--'`,---..-.--+--.,,-,,..._.--..-._.-a:f--." <<
			"\n\t";

			cout << endl;
	}

	if(weather=="Scattered Clouds"){
		cout <<
			"\n\t,--.::::::::::::::::::::::::::::::::::::....:::::::" <<
			"\n\t    )::::::::::::::::::::::::::::::::..      ..::::" <<
			"\n\t  _'-. _:::::::::::::::::::::::::::..   ,--.   ..::" <<
			"\n\t (    ) ),--.::::::::::::::::::::::.   (    )   .::" <<
			"\n\t             )-._::::::::::::::::::..   `--'   ..::" <<
			"\n\t_________________):::::::::::::::::::..      ..::::" <<
			"\n\t::::::::::::::::::::::::::::::::::::::::....:::::::" <<
			"\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::" <<
			"\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::" <<
			"\n\t!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!:!" <<
			"\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<
			"\n\t|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|!|" <<
			"\n\t|||||||||||||||||||||||||||||||||||||||||||||||||||" <<
			"\n\tI|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I|I" <<
			"\n\tIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
			cout << endl;
	}
}






// based on http://www.boost.org/doc/libs/1_51_0/doc/html/boost_asio/example/http/client/sync_client.cpp with minor modifications
//
// sync_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

string get_http(const string &server,const string &path){
	 using boost::asio::ip::tcp;
	 stringstream result;
	 boost::asio::io_service io_service;

	 // Get a list of endpoints corresponding to the server name.
	 //cout << "Resolving host name..." << endl;
	 tcp::resolver resolver(io_service);
	 tcp::resolver::query query(server, "http");
	 tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	 

	 // Try each endpoint until we successfully establish a connection.
	 //cout << "Establishing Connection..." << endl;
	 tcp::socket socket(io_service);
	 boost::asio::connect(socket, endpoint_iterator);
	 

	 // Form the request. We specify the "Connection: close" header so that the
	 // server will close the socket after transmitting the response. This will
	 // allow us to treat all data up until the EOF as the content.
	 //cout << "Forming Request..." << endl;
	 boost::asio::streambuf request;
	 std::ostream request_stream(&request);
	 request_stream << "GET " << path << " HTTP/1.0\r\n";
	 request_stream << "Host: " << server << "\r\n";
	 request_stream << "Accept: */*\r\n";
	 request_stream << "Connection: close\r\n\r\n";
	 

	 // Send the request.
	 //cout << "Sending Request..." << endl;
	 boost::asio::write(socket, request);
	 

	 // Read the response status line. The response streambuf will automatically
	 // grow to accommodate the entire line. The growth may be limited by passing
	 // a maximum size to the streambuf constructor.
	 //cout << "Reading Response" << endl;
	 boost::asio::streambuf response;
	 boost::asio::read_until(socket, response, "\r\n");
	 

	 // Check that response is OK.
	 //cout << "Checking Response" << endl;
	 std::istream response_stream(&response);
	 std::string http_version;
	 response_stream >> http_version;
	 unsigned int status_code;
	 response_stream >> status_code;
	 std::string status_message;
	 std::getline(response_stream, status_message);
	 if (!response_stream || http_version.substr(0, 5) != "HTTP/"){
		throw runtime_error("Invalid response");
	 }
	 if (status_code != 200){
		stringstream ss;
		ss<< "Response returned with status code " << status_code << "\n";
		 throw runtime_error(ss.str());
	 }
	 // Read the response headers, which are terminated by a blank line.
	 //cout << "Reading Response Headers..." << endl;
	 boost::asio::read_until(socket, response, "\r\n\r\n");

	 // Process the response headers.
	 std::string header;
	 while (std::getline(response_stream, header) && header != "\r");
	 // std::cout << header << "\n";
	 //std::cout << "\n";

	 // Write whatever content we already have to output.
	 //cout << "Writing Content..." << endl;
	 if (response.size() > 0)
		result << &response;

	 // Read until EOF, writing data to output as we go.
	 boost::system::error_code error;
	 while (boost::asio::read(socket, response,
			boost::asio::transfer_at_least(1), error))
		result << &response;
	 if (error != boost::asio::error::eof)
		throw boost::system::system_error(error);

	 return result.str();
}