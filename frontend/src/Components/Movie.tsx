import { type Movie } from "../types/movies_types";

interface MovieProps {
  data: Movie;
}

const MovieCard = ({ data }: MovieProps) => {
  return (
    <div className="movie-card">
      <h2>{data.name}</h2>
      
      <div className="movie-details">
        <span className="badge">{data.category}</span>
        <span>{data.year}</span>
        <span className="rating"> {data.rate.toFixed(1)}</span>
      </div>

      <div className="movie-info">
        <p><strong>Origem:</strong> {data.origin}</p>
        <p><strong>Estilo:</strong> {data.style}</p>
        <p><strong>Ritmo:</strong> {data.pace}</p>
      </div>
    </div>
  );
};

export default MovieCard;