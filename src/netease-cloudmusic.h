#ifndef CPP_NETEASE_CLOUDMUSIC_HPP
#define CPP_NETEASE_CLOUDMUSIC_HPP

#include <nlohmann/json.hpp>
#include <cstdint>
#include <string>
#include <string_view>
#include <optional>
#include <vector>

namespace haceau::netease::cloudmusic {

  ///
  /// @brief 网易云音乐 API 的地址。
  ///
  inline char const* base_url{ "http://cloud-music.pl-fe.cn" };

  ///
  /// @brief 搜索类型
  ///
  enum class search_type {
    single = 1,
    collection = 10,
    artist = 100,
    song_list = 1000,
    user = 1002,
    mv = 1004,
    lyric = 1006,
    radio_station = 1009,
    video = 1014,
    comprehensive = 1018,
    voice = 2000
  };

  ///
  /// @brief 歌手信息。
  ///
  struct artist_information {
    std::int32_t id;
    std::string name;
    std::int32_t picture_id;
    std::int32_t album_size;
    std::string image_1v1_url;
    std::int32_t image_1v1;
  };
  ///
  /// @brief 歌手信息 JSON 反序列化。
  ///
  auto from_json(nlohmann::json const& j, artist_information& info) -> void;

  ///
  /// @brief 专辑信息。
  ///
  struct album_information {
    std::int32_t id;
    std::string name;
    artist_information artist;
    std::int64_t publish_time;
    std::int32_t size;
    std::int32_t copyright_id;
    std::int32_t status;
    std::int64_t picture_id;
    std::int32_t mark;
  };
  ///
  /// @brief 专辑信息 JSON 反序列化。
  ///
  auto from_json(nlohmann::json const& j, album_information& info) -> void;

  ///
  /// @brief 歌曲信息。
  ///
  struct song_information {
    std::int32_t id;
    std::string name;
    std::vector<artist_information> artists;
    album_information album;
    std::int32_t duration;
    std::int32_t copyright_id;
    std::int32_t status;
    std::int32_t rtype;
    std::int32_t ftype;
    std::int32_t mvid;
    std::int32_t fee;
    std::string r_url;
    std::int32_t mark;
  };
  ///
  /// @brief 歌曲信息 JSON 反序列化。
  ///
  auto from_json(nlohmann::json const& j, song_information& info) -> void;

  ///
  /// @brief 搜索结果。
  ///
  struct search_result {
    std::vector<song_information> songs;
    bool has_more;
    std::int32_t song_count;
  };
  ///
  /// @brief 搜索结果 JSON 反序列化。
  ///
  auto from_json(nlohmann::json const& j, search_result& info) -> void;

  ///
  /// @brief 搜索音乐 / 专辑 / 歌手 / 用户。
  ///
  auto search(std::string keywords,
              std::optional<std::int32_t> limit = std::nullopt,
              std::optional<std::int32_t> offset = std::nullopt,
              std::optional<search_type> type = std::nullopt) -> search_result;
}

#endif // CPP_NETEASE_CLOUDMUSIC_HPP