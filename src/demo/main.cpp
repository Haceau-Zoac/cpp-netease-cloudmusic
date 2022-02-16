#include <iostream>
#include "netease-cloudmusic.h"

auto main() -> int {
  auto result{ haceau::netease::cloudmusic::search("omg", 5) };
  for (auto const& song : result.songs) {
    std::cout << "song: " << song.name << std::endl;
    std::cout << "artist: ";
    for (auto const& artist : song.artists) {
      std::cout << artist.name << " ";
    }
    std::cout << std::endl;
  }
}