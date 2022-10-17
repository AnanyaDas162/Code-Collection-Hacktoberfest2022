import { Stack, Box } from "@mui/material";
import { ChannelCard, VideoCard } from "./";
import { Loader } from "./";

const Videos = ({ videos, direction }) => {
  if (!videos?.length) return <Loader />;

  return (
    <Stack
      direction={direction || "row"}
      flexWrap='wrap'
      justifyContent='start'
      gap={2}>
      {videos.map((item, idx) => (
        <Box>
          {item.id.videoId && <VideoCard video={item} />}
          {item.id.channelId && <ChannelCard channelDetail={item} />}
        </Box>
      ))}
    </Stack>
  );
};

export default Videos;
