# cpp-netease-cludmusic

一个易用的 C++17 [网易云音乐 API](https://neteasecloudmusicapi.vercel.app/) 封装库。

## 依赖

此项目依赖 [cpp-httplib](https://github.com/yhirose/cpp-httplib) 及 [nlohmnn_json](https://github.com/nlohmann/json) 库。

## 例子

```cpp
#include <iostream>
#include "netease-cloudmusic.h"

auto main() -> int {
  // 搜索
  auto result{ haceau::netease::cloudmusic::search("omg", 5) };
  // 遍历所有歌曲
  for (auto const& song : result.songs) {
    // 歌曲名
    std::cout << "song: " << song.name << std::endl;
    // 歌手
    std::cout << "artist: ";
    // 遍历所有歌手
    for (auto const& artist : song.artists) {
      // 歌手名
      std::cout << artist.name << " ";
    }
  }
}
```
