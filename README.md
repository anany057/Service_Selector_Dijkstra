# Service_Selector_Dijkstra


The main goal of the project is to create a MatchMate Management System that facilitates event planning, particularly focusing on wedding events. The system allows users to create accounts and find ideal matchmates based on their preferences. Additionally, the system provides a curated list of service providers for services like Photography, Catering, Flowers, and Music. The primary purpose is to offer users an interactive and user-friendly platform to efficiently plan their events.

Functionality:

User Account Creation: Users can create accounts by providing essential details such as name, age, gender, and religion. They can also specify their preferences regarding age, religion, and the type of match they are seeking.

Matchmaking: The system employs a matchmaking algorithm to evaluate the compatibility of two users based on their preferences. The algorithm considers age preference, religion preference, and gender preference to calculate a match score. The match score helps users identify suitable matchmates.

Service Providers: The system provides a pre-defined list of service providers for event planning, categorized into four groups: Photography, Catering, Flowers, and Music. Users can browse through these service providers, view their details, and select preferred services.

Budget Optimization: The project uses the Dijkstra algorithm to find the most economical combination of service providers for users who choose the Budget-Friendly option. This feature ensures cost-effective event planning by minimizing the total cost while providing quality services.

Data Structures:

Map:

The project utilizes the map data structure to store service providers along with their prices in four categories: Photography, Catering, Flowers, and Music. The map allows efficient retrieval of service providers based on their associated prices.
Vectors:

The project uses vector to store male and female candidates separately for matchmaking. The vectors hold the names of candidates based on their genders.
2D Vector (Graph):

The 2D vector (graph) is used to represent connections and costs between different nodes (service providers). The graph is used in the Dijkstra algorithm to find the most economical combination of service providers for Budget-Friendly booking.


https://github.com/anany057/Service_Selector_Dijkstra/assets/112336313/c9c5af9a-1379-4a9f-9132-11dbd851ea8a


https://github.com/anany057/Service_Selector_Dijkstra/assets/112336313/b5addb55-d069-4c0c-b147-02d1cd194929


