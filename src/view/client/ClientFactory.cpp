
#include <view/client/ClientFactory.hpp>
#include <view/client/ConsoleView.hpp>
#include <view/client/HttpView.hpp>

namespace view {
namespace client {

std::unique_ptr<ClientInterface> ClientFactory::createClient(ClientType type) {
  if (type == ClientType::CONSOLE) {
    return std::make_unique<ConsoleView>();
  } else if (type == ClientType::HTTP) {
    return std::make_unique<HttpView>();
  }

  return nullptr;
}
}  // namespace client
}  // namespace view