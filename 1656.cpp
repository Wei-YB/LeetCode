#include "util.h"

class OrderedStream {
public:
    OrderedStream(int n) : stream_(n + 1) {
        ;
    }

    vector<string> insert(int idKey, string value) {
        stream_[idKey] = value;
        if (ptr == idKey) {
            vector<string> result;
            while (ptr < stream_.size() && stream_[ptr].size() > 0) {
                result.push_back(stream_[ptr++]);
            }
            return result;
        }
        return {};
    }

    vector<string> stream_;
    int ptr = 1;
};