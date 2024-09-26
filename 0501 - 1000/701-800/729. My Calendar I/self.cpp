class MyCalendar {
    vector<pair<int, int>> reserv;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // Check for overlaps with existing reservations
        for (auto& range : reserv) {
            // Overlaps if start is less than end of range and end is greater than start of range
            if(start < range.second && end > range.first) return false; // There's an overlap
        }
        // If no overlaps, add the new reservation
        reserv.push_back({start, end});
        return true; // Booking successful
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */