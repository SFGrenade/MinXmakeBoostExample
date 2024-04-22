#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/type_index.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

int main( int argc, char** argv, char** envp ) {
  std::cout << "env:" << std::endl;
  for( char** env = envp; *env != 0; env++ ) {
    std::cout << "=> '" << ( *env ) << "'" << std::endl;
  }

  if( const char* pathEnv = std::getenv( "PATH" ) ) {
    std::cout << "Your PATH is: " << pathEnv << std::endl;
  }

  std::cout << "type of int8_t: " << boost::typeindex::type_id< int8_t >().pretty_name() << std::endl;
  std::cout << "type of uint8_t: " << boost::typeindex::type_id< uint8_t >().pretty_name() << std::endl;
  std::cout << "type of int16_t: " << boost::typeindex::type_id< int16_t >().pretty_name() << std::endl;
  std::cout << "type of uint16_t: " << boost::typeindex::type_id< uint16_t >().pretty_name() << std::endl;
  std::cout << "type of int32_t: " << boost::typeindex::type_id< int32_t >().pretty_name() << std::endl;
  std::cout << "type of uint32_t: " << boost::typeindex::type_id< uint32_t >().pretty_name() << std::endl;
  std::cout << "type of int64_t: " << boost::typeindex::type_id< int64_t >().pretty_name() << std::endl;
  std::cout << "type of uint64_t: " << boost::typeindex::type_id< uint64_t >().pretty_name() << std::endl;

  uint64_t myValue = 13337;

  std::stringstream contentString;

  boost::archive::text_oarchive oarchive( contentString );
  oarchive << myValue;

  contentString.seekg( 0, std::ios_base::beg );
  boost::archive::text_iarchive iarchive( contentString );

  uint64_t myReadValue;
  iarchive >> myReadValue;

  if( myValue != myReadValue ) {
    throw std::runtime_error( "Values not equal!" );
  }

  return 0;
}
