import "./movieList.css"
import type { Movie } from "../types/movies_types";
import MovieCard from "./Movie";

interface MovieListProps {
  movies: Movie[];
}

const MovieList = ({ movies }: MovieListProps) => {
  if (movies.length === 0) {
    return (
      <div className="no-results">
        <p>Puxa, não encontramos nenhum filme com esses critérios.</p>
        <p>Tente recomeçar o quiz!</p>
      </div>
    );
  }

  return (
    <div className="movie-list-container">
      <h2 className="list-title">Sugestões para você:</h2>
      <div className="movie-grid">
        {movies.map((item, index) => (
          <MovieCard 
            key={item.id ?? `movie-${index}`} 
            data={item} 
          />
        ))}
      </div>
    </div>
  );
};

export default MovieList;