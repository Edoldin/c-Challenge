#ifndef CLIENTFACTORY_HPP
#define CLIENTFACTORY_HPP

#include <memory>
#include <view/client/ClientInterface.hpp>

namespace view {
namespace client {

class ClientFactory {
 public:
  static std::unique_ptr<ClientInterface> createClient(ClientType type);
};
}  // namespace client
}  // namespace view
#endif  // CLIENTFACTORY_HPP
