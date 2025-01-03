#ifndef ZOSC_MESSAGE_HPP
#define ZOSC_MESSAGE_HPP

#include <boost/asio.hpp>
#include <cstdint>
#include <string>
#include <variant>
#include <vector>

// Define the OscArg as a variant of possible OSC types
using OscArg =
	std::variant<int32_t, float, std::string, std::vector<uint8_t>, uint32_t>;

/**
 * @brief Encapsulates an OSC message
 * @details This class represents an OSC message, composed of a string that 
 * contains an address pattern followed by a list of arguments.
 *
 * @class ZoscMessage
 * @ingroup OSC Data Types
 */
class ZoscMessage {
  public:
	// Constructors
	ZoscMessage() = default;
	explicit ZoscMessage(const std::string &address);

	// Getters
	const std::string &getAddress() const;
	const std::vector<OscArg> &getArgs() const;

	// Setters
	void setAddress(const std::string &address);
	void addArgument(const OscArg &arg);

	// Serialization and Deserialization
	std::string serialize() const;
	static ZoscMessage deserialize(const std::string &data);

  private:
	std::string _address;           // OSC address pattern
	std::vector<OscArg> _arguments; // Arguments of the message
};

// Overload operator<< for the OscArg variant
std::ostream &operator<<(std::ostream &os, const OscArg &arg);

#endif // ZOSC_MESSAGE_HPP
