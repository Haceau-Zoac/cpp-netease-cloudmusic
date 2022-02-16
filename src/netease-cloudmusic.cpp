#include "netease-cloudmusic.h"
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
using namespace nlohmann;

namespace haceau::netease::cloudmusic {

  auto search(std::string keywords, std::optional<std::int32_t> limit, std::optional<std::int32_t> offset, std::optional<search_type> type) -> search_result {
    httplib::Client client((base_url));
    std::string url{ "/search?keywords=" + keywords };
    if (limit.has_value()) {
      url += "&limit=" + std::to_string(limit.value());
    }
    if (offset.has_value()) {
      url += "&offset=" + std::to_string(offset.value());
    }
    if (type.has_value()) {
      url += "&type=" + std::to_string(static_cast<std::int32_t>(type.value()));
    }
    auto res{ client.Get(url.c_str()) };
    auto json{ json::parse(res->body) };
    return json.get<search_result>();
  }

  
  auto from_json(nlohmann::json const& j, artist_information& info) -> void {
    j.at("id").get_to(info.id);
    j.at("name").get_to(info.name);
    j.at("picId").get_to(info.picture_id);
    j.at("albumSize").get_to(info.album_size);
    j.at("img1v1").get_to(info.image_1v1);
    j.at("img1v1Url").get_to(info.image_1v1_url);
  }

  auto from_json(nlohmann::json const& j, album_information& info) -> void {
    j.at("artist").get_to(info.artist);
    j.at("name").get_to(info.name);
    j.at("id").get_to(info.id);
    j.at("publishTime").get_to(info.publish_time);
    j.at("size").get_to(info.size);
    j.at("copyrightId").get_to(info.copyright_id);
    j.at("status").get_to(info.status);
    j.at("picId").get_to(info.picture_id);
    j.at("mark").get_to(info.mark);
  }

  auto from_json(nlohmann::json const& j, song_information& info) -> void {
    j.at("artists").get_to(info.artists);
    j.at("name").get_to(info.name);
    j.at("duration").get_to(info.duration);
    j.at("copyrightId").get_to(info.copyright_id);
    j.at("status").get_to(info.status);
    j.at("rtype").get_to(info.rtype);
    j.at("ftype").get_to(info.ftype);
    j.at("mvid").get_to(info.mvid);
    j.at("fee").get_to(info.fee);
    j.at("rUrl").get_to(info.r_url);
    j.at("mark").get_to(info.mark);
  }

  auto from_json(nlohmann::json const& j, search_result& info) -> void {
    auto res{ j.at("result") };
    res.at("songs").get_to(info.songs);
    res.at("hasMore").get_to(info.has_more);
    res.at("songCount").get_to(info.song_count);
  }
}